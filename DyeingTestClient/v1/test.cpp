#include <iostream>
#include <string>

#include "servant/Communicator.h"
#include "Test.h"
#include "servant/TarsLogger.h"
#include "util/tc_option.h"
#include "util/tc_file.h"

using namespace std;
using namespace tars;

int main(int argc, char **argv)
{
    try
    { // 初始化通信代理，用于调用服务（无需关注）
        CommunicatorPtr comm = new Communicator();
        comm->setProperty("locator", "tars.tarsregistry.QueryObj@tcp -h 9.135.91.218 -p 17890 -t 10000");
        TarsRollLogger::getInstance()->setLogInfo("TestApp", "TestServer", "./log", 100000, 10, comm, "tars.tarslog.LogObj");
        TarsRollLogger::getInstance()->sync(false);
        TarsTimeLogger::getInstance()->setLogInfo(comm, "tars.tarslog.LogObj", "TestApp", "TestServer", "./log");

        {
            //在打开染色日志之前，打印日志，这条日志只会打印到本地日中。
            TLOGDEBUG(__FILE__ << "|" << __LINE__ << "|" << "Test Before Dyeing" << endl);
            DLOG   << __FILE__ << "|" << __LINE__ << "|" << "D/Test Before Dyeing" << endl;
        }
        {
            //声明一个日志打开开关，调用enableDyeing打开染色日志
            TarsDyeingSwitch dye;
            dye.enableDyeing();

            //在打开染色日志之后，打印日志，会在本地日志和染色日志中看到
            {
                TLOGDEBUG(__FILE__ << "|" << __LINE__ << "|" << "Test After Dyeing" << endl);
                DLOG   << __FILE__ << "|" << __LINE__ << "|" << "D/Test After Dyeing" << endl;
            }

            string sServant = "TestApp.TestServer.TestObj";
            TestApp::TestPrx prx = comm->stringToProxy<TestApp::TestPrx>(sServant);
            string output;
            // 调用 test 接口
            prx->test("hello", output);
        }

        //染色日志开关已经析构，染色功能失效，以后的日志不会打印到染色日志中
        TLOGDEBUG(__FILE__ << "|" << __LINE__ << "|" << "~Dyeing" << endl);
        DLOG   << __FILE__ << "|" << __LINE__ << "|" << "D/~Dyeing" << endl;
    }
    catch (exception &e)
    {
        cerr << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << endl;
    }
    sleep(10); //等待异步写日志线程同步日志数据到 logserver
    return 0;
}
