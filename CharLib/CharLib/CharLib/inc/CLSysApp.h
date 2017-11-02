#ifndef _CL_SYS_APP_H_
#define _CL_SYS_APP_H_

#include "CLObject.h"


namespace cl 
{
	class CLSysApp : public CLObject
	{
	public:
		typedef void(*run_thread_func_type)();
		CLSysApp();
		CLSysApp(int argc, char **argv);
		virtual ~CLSysApp();
		virtual void run() = 0;

	private:
		int		m_argc;
		char	**m_argv;
	};

}


#endif
