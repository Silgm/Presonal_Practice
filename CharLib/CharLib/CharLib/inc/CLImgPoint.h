#ifndef _CL_IMGPOINT_H_
#define _CL_IMGPOINT_H_

#include "CLElm.h"

namespace cl {
	class CLImgPoint : public CLElm
	{
		
	public:
		using imgPoint_type = char_type;
		using imgPointGroup_type = std::vector<CLImgPoint>;
		CLImgPoint();
		CLImgPoint(coord_type x, coord_type y);
		CLImgPoint(coord_type x, coord_type y, imgPoint_type img);

		virtual ~CLImgPoint();

		void setImgPoint(imgPoint_type img);
		imgPoint_type getImgPoint() const;
		void show() const;

		CLImgPoint& operator=(const CLImgPoint& imgPoint);
	private:
		imgPoint_type m_img = L' ';
	};
}


#endif
