#include "CMainApp.h"
namespace gm {
	CMainApp::CMainApp()
		: cl::CLSysApp(0, nullptr)
	{

	}

	CMainApp::CMainApp(int argc, char * argv[])
		: cl::CLSysApp(argc, argv)
	{

	}

	CMainApp::~CMainApp()
	{
	}

}

