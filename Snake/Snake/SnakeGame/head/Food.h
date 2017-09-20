#ifndef		_FOOD_H_
#define		_FOOD_H_

#include "GameElementObject.h"
#include "ImagePoint.h"

namespace sg {
	class CFood : public CGameElementObject {
	
	public :
		CFood(CGameElementObject::TypeCoordinate xBound, CGameElementObject::TypeCoordinate yBound);
		virtual ~CFood();

		void reFlash();
		std::vector<CImagePoint> getImage();

	private:

		CGameElementObject::TypeCoordinate m_xBound;
		CGameElementObject::TypeCoordinate m_yBound;

	};
}


#endif
