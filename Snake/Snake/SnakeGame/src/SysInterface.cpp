#include "SysInterface.h"

namespace sg {

	constexpr size_t RENDER_FLAG_MAT_MAX_LEN = 50;

	CSysInterface::CSysInterface(CGameElementObject::TypeCoordinate width, CGameElementObject::TypeCoordinate height)
		: m_width(width), m_height(height)
	{
	}
	CSysInterface::~CSysInterface()
	{
	}
	bool CSysInterface::addImage(const std::vector<CImagePoint>& img)
	{
		bool isIn = true;
		for (auto elm : img) {
			if (!((elm.getCX() < m_width && elm.getCX() >= 0) &&
				(elm.getCY() < m_height && elm.getCY() >= 0)))
				isIn = false;

			m_imgBuff.push_back(elm);
		}
		return isIn;
	}
	void CSysInterface::clearBuff()
	{
		m_imgBuff.clear();
	}

	void CSysInterface::render()
	{
		HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;

		static bool flag = true;

		if (flag) {
			setlocale(LC_ALL, "");
			flag = false;
		}
		
		//std::vector<CImagePoint>::iterator it = m_imgBuff.begin();
		//渲染需要优化
		system("cls");


		for (auto elm : m_imgBuff) {
			SHORT x = elm.getCX(), y = elm.getCY();
			if ( x >= 0 && y >= 0)
			{
				position.X = elm.getCX() * 2;
				position.Y = elm.getCY();
				SetConsoleCursorPosition(hCmd, position);
				SetConsoleTextAttribute(hCmd, elm.getColor());
				putchar(elm.getShape());
			}
		}
		position.X = 0;
		position.Y = 0;
		SetConsoleCursorPosition(hCmd, position);
	}
}


