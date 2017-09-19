#ifndef _SYS_CONTROLLER_H_
#define _SYS_CONTROLLER_H_

#include "GameSystemObject.h"

namespace sg{

	class CSysController : public CGameSystemObject {
	public:
		using TypeKey = int;
		enum EnumKey // Function Key
		{
			KEY_NOKEY = -1,
			KEY_ESC = 27,
			KEY_UP = 72,
			KEY_DOWN = 80,
			KEY_LEFT = 75,
			KEY_RIGHT = 77,
		};
		CSysController();
		virtual ~CSysController();

		TypeKey getKeyWithBuff();
		TypeKey getKeyCurt();
	private:

	};
}




#endif
