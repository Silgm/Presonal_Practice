#ifndef _IMAGE_POINT_H_
#define _IMAGE_POINT_H_

#include "GameElementObject.h"

#define CIMAGEPOINT_DEFAULT_SHAPE		('*')
#define CIMAGEPOINT_DEFAULT_COLOR		(COLOR_GRAY)

namespace sg {

	class CImagePoint : public CGameElementObject 
	{
	public:
		using TypeShape = CHAR;
		using TypeColor = DWORD;

		//Color enumerate
		enum EnumColor {
			COLOR_BLACK = 0,
			COLOR_BLUE = 1,
			COLOR_GREEN = 2,
			COLOR_BGREEN = 3,
			COLOR_RED = 4,
			COLOR_PURPLE = 5,
			COLOR_YELLOW = 6,
			COLOR_WHITE = 7,
			COLOR_GRAY = 8,
			COLOR_LBLUE = 9,
			COLOR_LGREEN = 10,
			COLOR_LBGREEN = 11,
			COLOR_LRED = 12,
			COLOR_LPURPLE = 13,
			COLOR_LYELLOW = 14,
			COLOR_BWHITE = 15
		};

		CImagePoint(TypeCoordinate x, TypeCoordinate y,
			TypeShape shape = CIMAGEPOINT_DEFAULT_SHAPE,
			TypeColor color = CIMAGEPOINT_DEFAULT_COLOR);

		CImagePoint::TypeShape getShape();
		CImagePoint::TypeColor getColor();

		virtual ~CImagePoint();
		
	private:
		TypeShape m_shape;
		TypeColor m_color;
	};
}

#endif
