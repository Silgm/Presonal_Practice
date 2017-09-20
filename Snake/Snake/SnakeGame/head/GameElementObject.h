#ifndef _GAME_ELEMENT_OBJECT_H_
#define _GAME_ELEMENT_OBJECT_H_

#include "GameObject.h"


namespace sg {
	class CGameElementObject : public CGameObject
	{

	public:
		using TypeCoordinate =  int32_t;
		
		CGameElementObject();
		CGameElementObject(TypeCoordinate x, TypeCoordinate y);
		virtual ~CGameElementObject();

		TypeCoordinate getCX();
		TypeCoordinate getCY();

		void setCX(TypeCoordinate cx);
		void setCY(TypeCoordinate cy);

		void moveUp();
		void moveUp(TypeCoordinate length);

		void moveDown();
		void moveDown(TypeCoordinate length);

		void moveLeft();
		void moveLeft(TypeCoordinate length);

		void moveRight();
		void moveRight(TypeCoordinate length);

	private:
		TypeCoordinate m_cx;
		TypeCoordinate m_cy;


	};
}


#endif
