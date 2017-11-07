#include "CLSysApp.h"
namespace cl
{
	CLSysApp::CLSysApp()
		: m_argc(0), m_argv(nullptr)
	{

	}

	CLSysApp::CLSysApp(int argc, char **argv)
		: m_argc(argc), m_argv(argv)
	{

	}

	CLSysApp::~CLSysApp()
	{
	}

	bool CLSysApp::setTitle(str_type str)
	{
		this->m_title = str;
		return SetConsoleTitleW(this->m_title.c_str());
	}
}



