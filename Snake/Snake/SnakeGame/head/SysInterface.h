#ifndef _SYS_INTERFACE_H_
#define _SYS_INTERFACE_H_

#include "GameSystemObject.h"
#include "ImagePoint.h"


namespace sg {
	class CSysInterface : public CGameSystemObject
	{

	public:
		CSysInterface(CGameElementObject::TypeCoordinate width, CGameElementObject::TypeCoordinate height);
		virtual ~CSysInterface();
		void addImage(const std::vector<CImagePoint> &img);
		void clearBuff();
		void render();
	private:
		std::vector<CImagePoint> m_imgBuff;
		CGameElementObject::TypeCoordinate m_width;
		CGameElementObject::TypeCoordinate m_height;
	};
}

#endif
