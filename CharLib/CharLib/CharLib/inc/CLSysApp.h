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
		virtual void run() = 0;

	private:
		int	m_argc;
		char **m_argv;
	};

}


#endif
