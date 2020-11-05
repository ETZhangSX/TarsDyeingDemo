#include <iostream>
#include <string>

#include "servant/Communicator.h"
#include "util/tc_option.h"
#include "util/tc_file.h"

#include "Test.h"

using namespace std;
using namespace tars;

int main(int argc,char ** argv)
{
    try
    {   // 初始化通信代理，用于调用服务（读者无需关注）
        CommunicatorPtr comm = new Communicator();
        comm->setProperty("locator", "tars.tarsregistry.QueryObj@tcp -h 192.168.0.121 -p 17890 -t 10000");

        // 生成调用代理
        TestApp::TestPrx prx = comm->stringToProxy<TestApp::TestPrx>("TestApp.TestServer.TestObj");
        string output;
        // 调用 test 接口, 传入染色id: 123456
        prx->test("123456", output);
        cout << output << endl;
        // 调用 test 接口, 传入非染色id: tars
        prx->test("tars", output);
        cout << output << endl;
    }
    catch(exception& e)
    {
        cerr << "exception:" << e.what() << endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << endl;
    }
    return 0;
}
