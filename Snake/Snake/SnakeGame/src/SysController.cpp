#include "SysController.h"

namespace sg {
	CSysController::CSysController()
	{
	}
	CSysController::~CSysController()
	{
	}

	CSysController::TypeKey CSysController::getKeyWithBuff()
	{
#if _MSC_VER >= 1900
		return _getch();
#else
		return _getch();
#endif
	}

	CSysController::TypeKey CSysController::getKeyCurt()
	{
#if _MSC_VER >= 1900
		if (_kbhit())
			return _getch();
		else
			return KEY_NOKEY;
#else
		if (kbhit())
			return getch();
		else
			return KEY_NOKEY;
#endif
	}


}

