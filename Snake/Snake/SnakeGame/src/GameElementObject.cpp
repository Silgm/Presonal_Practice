#include "GameElementObject.h"
namespace sg {
	CGameElementObject::CGameElementObject()
		: m_cx(0), m_cy(0)
	{
	}

	CGameElementObject::CGameElementObject(TypeCoordinate x, TypeCoordinate y)
		: m_cx(x), m_cy(y)
	{

	}

	CGameElementObject::~CGameElementObject()
	{
	}

	CGameElementObject::TypeCoordinate sg::CGameElementObject::getCX()
	{
		return m_cx;
	}


	CGameElementObject::TypeCoordinate sg::CGameElementObject::getCY()
	{
		return m_cy;
	}

	void CGameElementObject::setCX(TypeCoordinate cx)
	{
		m_cx = cx;
	}

	void CGameElementObject::setCY(TypeCoordinate cy)
	{
		m_cy = cy;
	}

	void CGameElementObject::moveUp()
	{
		++m_cy;
	}

	void CGameElementObject::moveUp(TypeCoordinate length)
	{
		m_cy += length;
	}

	void CGameElementObject::moveDown()
	{
		--m_cy;
	}

	void CGameElementObject::moveDown(TypeCoordinate length)
	{
		m_cy -= length;
	}

	void CGameElementObject::moveLeft()
	{
		--m_cx;
	}

	void CGameElementObject::moveLeft(TypeCoordinate length)
	{
		m_cx -= length;
	}

	void CGameElementObject::moveRight()
	{
		++m_cx;
	}

	void CGameElementObject::moveRight(TypeCoordinate length)
	{
		m_cx += length;
	}
}

