#ifndef _TestImp_H_
#define _TestImp_H_

#include "servant/Application.h"
#include "Test.h"

/**
 *
 *
 */
class TestImp : public TestApp::Test
{
public:
    /**
     *
     */
    virtual ~TestImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual int test(const string &id, string &output, tars::TarsCurrentPtr current);// { output = id;return 0;};
};
/////////////////////////////////////////////////////
#endif
