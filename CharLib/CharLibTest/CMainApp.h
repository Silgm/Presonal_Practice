#ifndef _CMAIN_APP_H_
#define _CMAIN_APP_H_

#include "CharLib.h"

namespace gm {

	class CMainApp;
	/*指向类的非静态成员函数的指针*/

	class CMainApp : public cl::CLSysApp
	{
	public :
		CMainApp();
		CMainApp(int argc, char *argv[]);
		virtual ~CMainApp();

	private:
	};


}

#endif
