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
	CLImgPoint::CLImgPoint(coord_type x, coord_type y, imgPoint_type img, enum_color clr)
		: CLElm(x, y), m_img(img), m_color(clr)
	{
	}
	CLImgPoint::~CLImgPoint()
	{
	}
	void CLImgPoint::setImgPoint(imgPoint_type img)
	{
		this->m_img = img;
	}
	void CLImgPoint::setImgColor(enum_color clr)
	{
		this->m_color = clr;
	}
	CLImgPoint::imgPoint_type CLImgPoint::getImgPoint() const
	{
		return this->m_img;
	}
	CLImgPoint::enum_color CLImgPoint::getImgColor() const
	{
		return this->m_color;
	}
	void CLImgPoint::show() const
	{
		std::wcout << this->m_img;
	}
	CLImgPoint & CLImgPoint::operator=(const CLImgPoint & imgPoint)
	{
		// TODO: �ڴ˴����� return ���
		return *this;
	}
}

