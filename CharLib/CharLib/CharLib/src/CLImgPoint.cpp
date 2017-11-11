#include "CLImgPoint.h"

namespace cl
{
	CLImgPoint::CLImgPoint()
		: CLElm(0, 0)
	{

	}
	CLImgPoint::CLImgPoint(coord_type x, coord_type y)
		: CLElm(x, y)
	{
	}
	CLImgPoint::CLImgPoint(coord_type x, coord_type y, imgPoint_type img)
		: CLElm(x, y), m_img(img)
	{

	}
	CLImgPoint::~CLImgPoint()
	{
	}
	void CLImgPoint::setImgPoint(imgPoint_type img)
	{
		this->m_img = img;
	}
	CLImgPoint::imgPoint_type CLImgPoint::getImgPoint() const
	{
		return this->m_img;
	}
	void CLImgPoint::show() const
	{
		std::wcout << this->m_img;
	}
	CLImgPoint & CLImgPoint::operator=(const CLImgPoint & imgPoint)
	{
		// TODO: 在此处插入 return 语句
		return *this;
	}
}

