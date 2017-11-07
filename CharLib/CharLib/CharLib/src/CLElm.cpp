#include "CLElm.h"

namespace cl {
	CLElm::CLElm()
	{
	}
	CLElm::CLElm(coord_type x, coord_type y)
		: m_x(x), m_y(y)
	{
	}
	CLElm::~CLElm()
	{
	}
	CLElm::coord_type CLElm::getCX()
	{
		return this->m_x;
	}
	CLElm::coord_type CLElm::getCY()
	{
		return this->m_y;
	}
	void CLElm::setCX(coord_type x)
	{
		this->m_x = x;
	}
	void CLElm::setCY(coord_type y)
	{
		this->m_y = y;
	}
	void CLElm::setCoord(coord_type x, coord_type y)
	{
		this->m_x = x;
		this->m_y = y;
	}
	void CLElm::moveUp()
	{
		this->m_y -= 1;
	}
	void CLElm::moveUp(coord_type length)
	{
		this->m_y -= length;
	}
	void CLElm::moveDown()
	{
		this->m_y += 1;
	}
	void CLElm::moveDown(coord_type length)
	{
		this->m_y += length;
	}
	void CLElm::moveLeft()
	{
		this->m_x -= 1;
	}
	void CLElm::moveLeft(coord_type length)
	{
		this->m_x -= length;
	}
	void CLElm::moveRight()
	{
		this->m_x += 1;
	}
	void CLElm::moveRight(coord_type length)
	{
		this->m_x += length;
	}
}