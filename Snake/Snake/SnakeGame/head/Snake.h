#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "GameElementObject.h"
#include "ImagePoint.h"

namespace sg {
	class CSnake : public CGameElementObject
	{
	public:
		using TypeLength	= uint32_t;
		using TypeMoveDir = uint8_t;

		enum EnumMoveDir
		{
			DIR_UP = 0,
			DIR_DOWN = 1,
			DIR_LEFT = 2,
			DIR_RIGHT = 3
		};

		CSnake(TypeCoordinate start_cx, 
			TypeCoordinate start_cy, 
			TypeMoveDir start_dir, 
			TypeLength start_length);

		bool setDir(TypeMoveDir dir);
		TypeMoveDir getDir();

		void setLength(TypeLength length);
		TypeMoveDir getLength();

		void move();
		void growMove();

	private:
		std::vector<CImagePoint> m_body;
		TypeMoveDir	m_dir;
		TypeLength	m_length;

		void moveHead();
		void moveBody();
	};

}

#endif
