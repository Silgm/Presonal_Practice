#include "CLInterface.h"

namespace cl {



	CLInterface::CLInterface()
		: CLElm(0, 0)
	{
		init_interface();
	}

	CLInterface::CLInterface(coord_type x, coord_type y)
		: CLElm(x, y)
	{
		init_interface();
	}

	CLInterface::CLInterface(coord_type x, coord_type y, size_type width, size_type height)
		: CLElm(x, y), m_width(width), m_height(height)
	{
		init_interface();
		this->m_interface->resize(height);
		for (auto &elm : *m_interface)
		{
			elm.resize(width);
		}
	}

	CLInterface::~CLInterface()
	{

		delete this->m_interface;
	}

	void CLInterface::addImgPoint(const CLImgPoint &imgPoint)
	{
		CLImgPoint::coord_type cx = imgPoint.getCY(), cy = imgPoint.getCX();
		if (cx < static_cast<CLImgPoint::coord_type>(this->m_height) && cx >= 0
			&& cy < static_cast<CLImgPoint::coord_type>(this->m_width) && cy >= 0)
		{
			size_t x = cx, y = cy;
			((*(this->m_interface))[x][y]).setImgPoint(imgPoint.getImgPoint());
			((*(this->m_interface))[x][y]).setImgColor(imgPoint.getImgColor());
		}

	}

	void CLInterface::addImgPointGroup(const CLImgPoint::imgPointGroup_type & imgGroup)
	{
		for (const auto &elm : imgGroup)
		{
			this->addImgPoint(elm);
		}
	}

	void CLInterface::clear()
	{
		for (auto &elmLine : *m_interface)
		{
			for (auto &elm : elmLine)
			{
				elm.setImgPoint(L' ');
				elm.setImgColor(CLImgPoint::COLOR_GRAY);
			}
		}
	}

	void CLInterface::render() const
	{
		COORD position = {short(this->getCX()), short(this->getCY())};
		SetConsoleCursorPosition(this->hCmd, position);
		
		for (const auto &elmLine : *m_interface)
		{
			for (const auto &elm : elmLine)
			{
				SetConsoleTextAttribute(this->hCmd, elm.getImgColor());
				elm.show();
				std::wcout << L' ';
			}
			std::wcout << std::endl;
		}
	}

	CLInterface::size_type CLInterface::getWidth() const
	{
		return this->m_width;
	}

	CLInterface::size_type CLInterface::getHeight() const
	{
		return this->m_height;
	}

	void CLInterface::init_interface()
	{
		this->m_interface = new std::vector<std::vector<CLImgPoint>>;
	}

}