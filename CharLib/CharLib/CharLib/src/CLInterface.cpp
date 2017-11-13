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

	CLInterface::CLInterface(coord_type x, coord_type y, size_type width, size_type height, bool hasBound)
		: CLElm(x, y), m_width(width), m_height(height)
	{
		init_interface();
		this->m_interface->resize(height);
		for (auto &elm : *m_interface)
		{
			elm.resize(width);
		}
		this->m_hasBound = hasBound;

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

	void CLInterface::render()
	{
		if (this->m_hasBound && !this->m_hasShowBound)
		{
			COORD positionBound = { SHORT(this->getCX() - 1), SHORT(this->getCY() - 1) };
			//打印上边界
			for (; positionBound.X < SHORT((this->getCX() + 2*this->m_width )); ++positionBound.X)
			{
				if (positionBound.X >= 0 && positionBound.Y >= 0)
				{
					SetConsoleCursorPosition(this->hCmd, positionBound);
					std::wcout << L'━';
				}
			}
			//打印右上拐角
			if (positionBound.X >= 0 && positionBound.Y >= 0)
				std::wcout << L'┓';
			//打印右边界
			for (++positionBound.Y; positionBound.Y < SHORT((this->getCY() + this->m_height)); ++positionBound.Y)
			{
				if (positionBound.X >= 0 && positionBound.Y >= 0)
				{
					SetConsoleCursorPosition(this->hCmd, positionBound);
					std::wcout << L'┃';
				}
			}
			//打印右下拐角
			if (positionBound.X >= 0 && positionBound.Y >= 0)
			{
				SetConsoleCursorPosition(this->hCmd, positionBound);
				std::wcout << L'┛';
			}
			//打印右下拐角打印下边界
			for (--positionBound.X; positionBound.X >= SHORT((this->getCX())); --positionBound.X)
			{
				if (positionBound.X >= 0 && positionBound.Y >= 0)
				{
					SetConsoleCursorPosition(this->hCmd, positionBound);
					std::wcout << L'━';
				}
			}
			//打印右下边界
			SetConsoleCursorPosition(this->hCmd, positionBound);
			std::wcout << L'┗';

			//打印左边界
			for (--positionBound.Y; positionBound.Y >= SHORT((this->getCY())); --positionBound.Y)
			{
				if (positionBound.X >= 0 && positionBound.Y >= 0)
				{
					SetConsoleCursorPosition(this->hCmd, positionBound);
					std::wcout << L'┃';
				}
			}
			SetConsoleCursorPosition(this->hCmd, positionBound);
			std::wcout << L'┏';
			this->m_hasShowBound = true;
		}


		COORD position = { SHORT(this->getCX()), SHORT(this->getCY()) };
		SHORT line = 0;
		SetConsoleCursorPosition(this->hCmd, position);
		for (const auto &elmLine : *m_interface)
		{
			size_t index = 0;
			for (const auto &elm : elmLine)
			{
				SetConsoleTextAttribute(this->hCmd, elm.getImgColor());
				elm.show();
				if (index < this->m_width - 1)
				{
					++index;
					std::wcout << L' ';
				}
			}
			++line;
			COORD position = { SHORT(this->getCX()), SHORT(this->getCY() + line) };
			SetConsoleCursorPosition(this->hCmd, position);
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