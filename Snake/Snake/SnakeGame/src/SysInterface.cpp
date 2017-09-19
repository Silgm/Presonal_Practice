#include "SysInterface.h"
namespace sg {
	CSysInterface::CSysInterface(CGameElementObject::TypeCoordinate width, CGameElementObject::TypeCoordinate height)
		: m_width(width), m_height(height)
	{
	}
	CSysInterface::~CSysInterface()
	{
	}
	void CSysInterface::addImage(const std::vector<CImagePoint>& img)
	{
		for (auto elm : img) {
			m_imgBuff.push_back(elm);
		}
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
			if (x < m_width && y < m_height 
				&& x >= 0 && y >= 0)
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


