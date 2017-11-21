#ifndef _CTEXT_H_
#define _CTEXT_H_

#include "CharLib.h"
namespace gm {
	class CText : cl::CLElm
	{
	public:
		CText();
		CText(const std::wstring& wstr);
		CText(const std::wstring& wstr, cl::CLElm::coord_type x, cl::CLElm::coord_type y);
		CText(const std::wstring& wstr, cl::CLElm::coord_type x, cl::CLElm::coord_type y, cl::CLImgPoint::enum_color color);
		virtual ~CText();
		const cl::CLImgPoint::imgPointGroup_type getImageGroup();
	private:
		std::wstring context = L"";
		cl::CLImgPoint::enum_color color = cl::CLImgPoint::COLOR_GRAY;
	};
}
#endif
