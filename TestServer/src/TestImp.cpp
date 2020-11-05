#include "TestImp.h"
#include "servant/Application.h"

using namespace std;

//////////////////////////////////////////////////////
void TestImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void TestImp::destroy()
{
    //destroy servant here:
    //...
}

int TestImp::test(const string &id, string &output, tars::TarsCurrentPtr current)
{
    //tars::ServantProxyThreadData* sptd = tars::ServantProxyThreadData::getData();
    //if (sptd && sptd->_dyeing){
    //    if (id == sptd->_dyeingKey)
    //
    //}
    string servantName =  ServerConfig::Application + "." + ServerConfig::ServerName + ".TestObj";

    if (tars::ServantHelperManager::getInstance()->isDyeingReq(id, servantName, "test")) {
        output = "Dyeing on";
        TLOGDEBUG(__FILE__ << "|" << __LINE__ << "|" << "Test"  << endl);
        return 0;
    }
    output = id;
    TLOGDEBUG(__FILE__ << "|" << __LINE__ << "|" << "Test" << endl);
    DLOG << __FILE__ << "|" << __LINE__ << "|" << "D/Test"  << endl;

    return 0;
}
