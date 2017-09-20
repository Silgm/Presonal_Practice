#include "Wall.h"

namespace sg {
	CWall::CWall(CGameElementObject::TypeCoordinate width, CGameElementObject::TypeCoordinate height)
		: m_width(width), m_height(height)
	{
	}

	CWall::~CWall()
	{
	}

	std::vector<CImagePoint> CWall::getImage()
	{
		std::vector<CImagePoint> imgVec;

		for (CGameElementObject::TypeCoordinate i = 0; i < m_width; ++i)
		{
			CImagePoint tmpImg(i, m_height, '-', CImagePoint::EnumColor::COLOR_BGREEN);
			imgVec.push_back(tmpImg);
		}

		for (CGameElementObject::TypeCoordinate i = 0; i < m_height; ++i)
		{
			CImagePoint tmpImg(m_width, i, '|', CImagePoint::EnumColor::COLOR_BGREEN);
			imgVec.push_back(tmpImg);
		}
		return imgVec;
	}

	
}


