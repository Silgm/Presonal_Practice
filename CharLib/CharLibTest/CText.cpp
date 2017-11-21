#include "CText.h"

namespace gm {
	CText::CText()
		: CLElm(0, 0)
	{
	}

	CText::CText(const std::wstring & wstr)
		: CLElm(0, 0)
	{
		this->context = wstr;
	}

	CText::CText(const std::wstring& wstr, cl::CLElm::coord_type x, cl::CLElm::coord_type y)
		: CLElm(x, y)
	{
		this->context = wstr;
	}

	CText::CText(const std::wstring & wstr, cl::CLElm::coord_type x, cl::CLElm::coord_type y, cl::CLImgPoint::enum_color color)
		: CLElm(x, y)
	{
		this->context = wstr;
		this->color = color;
	}

	CText::~CText()
	{
	}
	const cl::CLImgPoint::imgPointGroup_type CText::getImageGroup()
	{
		cl::CLImgPoint::imgPointGroup_type resultImageGroup;
		for (long index = 0, bound = long(this->context.length()); index < bound; ++index)
		{
			resultImageGroup.push_back(cl::CLImgPoint(this->getCX() + index, this->getCY(), this->context[index], this->color));
		}
		return resultImageGroup;
	}
}
