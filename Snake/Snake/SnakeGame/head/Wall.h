#ifndef _WALL_H_
#define _WALL_H_

#include "GameElementObject.h"
#include "ImagePoint.h"

namespace sg {
	class CWall : public CGameElementObject {

	public:
		CWall(CGameElementObject::TypeCoordinate width, CGameElementObject::TypeCoordinate height);
		virtual ~CWall();

		std::vector<CImagePoint> getImage();
		
	private:
		CGameElementObject::TypeCoordinate m_width;
		CGameElementObject::TypeCoordinate m_height;
	};
}




#endif

