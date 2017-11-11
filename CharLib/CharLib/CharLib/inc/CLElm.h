#ifndef _CLELM_H_
#define _CLELM_H_

#include "CLObject.h"

namespace cl {
	class CLElm : public CLObject
	{
		/************************************************************************/
		/* 
		Console
		---->x
		|
		|
		|
		y
		*/
		/************************************************************************/
	public:
		using coord_type = long;

		CLElm();
		CLElm(coord_type x, coord_type y);
		virtual ~CLElm();

		coord_type getCX() const;
		coord_type getCY() const;

		void setCX(coord_type x);
		void setCY(coord_type y);
		void setCoord(coord_type x, coord_type y);

		void moveUp();
		void moveUp(coord_type length);

		void moveDown();
		void moveDown(coord_type length);

		void moveLeft();
		void moveLeft(coord_type length);

		void moveRight();
		void moveRight(coord_type length);

	private:
		coord_type m_x = 0;
		coord_type m_y = 0;

	};
}


#endif
