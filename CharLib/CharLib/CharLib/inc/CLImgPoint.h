#ifndef _CL_IMGPOINT_H_
#define _CL_IMGPOINT_H_

#include "CLElm.h"

namespace cl {
	class CLImgPoint : public CLElm
	{
		
	public:
		using imgPoint_type = char_type;
		using imgPointGroup_type = std::vector<CLImgPoint>;
		enum enum_color
		{
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
		CLImgPoint();
		CLImgPoint(coord_type x, coord_type y);
		CLImgPoint(coord_type x, coord_type y, imgPoint_type img);
		CLImgPoint(coord_type x, coord_type y, imgPoint_type img, enum_color clr);

		virtual ~CLImgPoint();

		void setImgPoint(imgPoint_type img);
		void setImgColor(enum_color clr);
		imgPoint_type getImgPoint() const;
		enum_color getImgColor() const;
		void show() const;
		CLImgPoint& operator=(const CLImgPoint& imgPoint);
	private:
		imgPoint_type m_img = L' ';
		enum_color m_color = COLOR_GRAY;
	};
}


#endif
