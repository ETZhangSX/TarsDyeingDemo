#include "TestServer.h"
#include "TestImp.h"

using namespace std;

TestServer g_app;

/////////////////////////////////////////////////////////////////
void
TestServer::initialize()
{
    //initialize application here:
    //...

    addServant<TestImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".TestObj");
}
/////////////////////////////////////////////////////////////////
void
TestServer::destroyApp()
{
    //destroy application here:
    //...
}
/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////
