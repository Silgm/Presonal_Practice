#include "CLSysApp.h"

cl::CLSysApp::CLSysApp()
	: m_argc(0), m_argv(nullptr)
{

}

cl::CLSysApp::CLSysApp(int argc, char **argv)
	: m_argc(argc), m_argv(argv)
{

}

cl::CLSysApp::~CLSysApp()
{
}

