#ifndef _GAME_ELEMENT_OBJECT_H_
#define _GAME_ELEMENT_OBJECT_H_

#include "GameObject.h"

namespace sg {
	class CGameElementObject : public CGameObject
	{

	public:
		using TypeCoordinate = unsigned int;
		CGameElementObject();
		CGameElementObject(TypeCoordinate x, TypeCoordinate y);
		virtual ~CGameElementObject();

	private:
		TypeCoordinate m_cx;
		TypeCoordinate m_cy;


	};
}


#endif
