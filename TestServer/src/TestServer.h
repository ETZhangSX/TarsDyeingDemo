#ifndef _TestServer_H_
#define _TestServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class TestServer : public Application
{
public:
    /**
     *
     **/
    virtual ~TestServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern TestServer g_app;

////////////////////////////////////////////
#endif
