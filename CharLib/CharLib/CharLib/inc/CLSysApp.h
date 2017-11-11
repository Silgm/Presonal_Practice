#ifndef _CL_SYS_APP_H_
#define _CL_SYS_APP_H_
#include "CLSys.h"


namespace cl 
{

	class CLSysApp : public CLSys
	{
	public:
		CLSysApp();
		CLSysApp(int argc, char **argv);
		virtual ~CLSysApp();

		bool setTitle(str_type str);
		void setLocaleLanguage(std::string locale);
	private:
		int	m_argc;
		char **m_argv;

		str_type m_title;
	};

}


#endif
