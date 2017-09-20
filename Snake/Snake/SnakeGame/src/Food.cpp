#include "Food.h"
namespace sg {

	CFood::CFood(CGameElementObject::TypeCoordinate xBound, CGameElementObject::TypeCoordinate yBound)
		: m_xBound(xBound), m_yBound(yBound)
	{
		setCX(tool::tool_random(2, m_xBound - 2));
		setCY(tool::tool_random(2, m_yBound - 2));
	}

	CFood::~CFood()
	{
	}

	void CFood::reFlash()
	{
		setCX(tool::tool_random(2, m_xBound - 2));
		setCY(tool::tool_random(2, m_yBound - 2));
	}

	std::vector<CImagePoint> CFood::getImage()
	{
		std::vector<CImagePoint> tmpVec;
		CImagePoint tmpImg(getCX(), getCY(), '#', CImagePoint::EnumColor::COLOR_LYELLOW);
		tmpVec.push_back(tmpImg);
		return tmpVec;
	}




}

