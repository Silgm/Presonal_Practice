#ifndef _CL_INTERFACE_H_
#define _CL_INTERFACE_H_

#include "CLElm.h"
#include "CLImgPoint.h"

namespace cl {
	class CLInterface : public CLElm
	{

	public:
		using size_type = size_t;
		CLInterface();
		CLInterface(coord_type x, coord_type y);
		CLInterface(coord_type x, coord_type y, size_type width, size_type height);
		CLInterface(coord_type x, coord_type y, size_type width, size_type height, bool hasBound);

		virtual ~CLInterface();
		void addImgPoint(const CLImgPoint &imgPoint);
		void addImgPointGroup(const CLImgPoint::imgPointGroup_type &imgGroup);
		void clear();
		void render();

		size_type getWidth() const;
		size_type getHeight() const;

		std::vector<std::vector<CLImgPoint>> *m_interface = nullptr;

	private:
		size_type m_width = 0;
		size_type m_height = 0;
		bool m_hasBound = false;
		bool m_hasShowBound = false;
		HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
		

		void init_interface();

	};
}

#endif
