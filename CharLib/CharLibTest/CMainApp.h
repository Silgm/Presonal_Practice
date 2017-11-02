#ifndef _CMAIN_APP_H_
#define _CMAIN_APP_H_

#include "CharLib.h"

namespace gm {
	class CMainApp : cl::CLSysApp
	{
	public :
		CMainApp();
		CMainApp(int argc, char *argv[]);
		virtual ~CMainApp();
		void run();
	private:

	};
}

#endif
