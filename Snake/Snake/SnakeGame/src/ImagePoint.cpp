#include "ImagePoint.h"


namespace sg {

	CImagePoint::CImagePoint(TypeCoordinate x, TypeCoordinate y, TypeShape shape, TypeColor color)
		: CGameElementObject(x, y), m_shape(shape), m_color(color)
	{

	}

	CImagePoint::TypeShape CImagePoint::getShape()
	{
		return m_shape;
	}

	CImagePoint::TypeColor CImagePoint::getColor()
	{
		return m_color;
	}

	CImagePoint::~CImagePoint()
	{

	}
}


