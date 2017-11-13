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
	void CLSysApp::setLocaleLanguage(std::string locale)
	{
		std::wcout.imbue(std::locale(locale));
	}
	void CLSysApp::setCursor(bool isShow, DWORD size)
	{
		CONSOLE_CURSOR_INFO curInfo = { size, isShow };
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	}

	void CLSysApp::setCosoleSize(int line, int col)
	{

		std::string cmd = std::string("mode con cols=") + std::to_string(col) + " " + std::string("lines=") + std::to_string(line);
		std::system(cmd.c_str());
	}

}



