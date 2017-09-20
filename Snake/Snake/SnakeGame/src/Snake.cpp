#include "Snake.h"

namespace sg {
	CSnake::CSnake(TypeCoordinate start_cx,
		TypeCoordinate start_cy,
		TypeMoveDir start_dir,
		TypeLength start_length)
		: CGameElementObject(start_cx, start_cy), m_dir(start_dir), m_length(start_length)
	{
		////CImagePoint's coordinate is absolute.
		CImagePoint head(start_cx, start_cy, cm_defaultHeadShape, cm_defaultColor);
		m_body.push_back(head);

		//Create the body of Snake
		switch (m_dir)
		{
		case DIR_UP:
			for (int index = 1; index < (int)m_length; ++index) {
				CImagePoint temp2(start_cx, start_cy - index, cm_defaultBodyShape, cm_defaultColor);
				m_body.push_back(temp2);
			}
			break;

		case DIR_DOWN:
			for (int index = 1; index < (int)m_length; ++index) {
				CImagePoint temp2(start_cx, start_cy + index, cm_defaultBodyShape, cm_defaultColor);
				m_body.push_back(temp2);
			}
			break;

		case DIR_LEFT:
			for (int index = 1; index < (int)m_length; ++index) {
				CImagePoint temp2(start_cx + index, start_cy, cm_defaultBodyShape, cm_defaultColor);
				m_body.push_back(temp2);
			}
			break;

		case DIR_RIGHT:
			for (int index = 1; index < (int)m_length; ++index) {
				CImagePoint temp2(start_cx - index, start_cy, cm_defaultBodyShape, cm_defaultColor);
				m_body.push_back(temp2);
			}
			break;

		default://the default case is DIR_LEFT
			for (int index = 1; index < (int)m_length; ++index) {
				CImagePoint temp2(start_cx - index, start_cy, cm_defaultBodyShape, cm_defaultColor);
				m_body.push_back(temp2);
			}
			break;
		}

	}

	bool CSnake::setDir(TypeMoveDir dir)
	{
		if ((m_dir == DIR_UP && dir == DIR_DOWN) ||
			(m_dir == DIR_DOWN && dir == DIR_UP) ||
			(m_dir == DIR_LEFT && dir == DIR_RIGHT) ||
			(m_dir == DIR_RIGHT && dir == DIR_LEFT)
			)
			return false;
		
		m_dir = dir;
		return true;
	}

	CSnake::TypeMoveDir CSnake::getDir()
	{
		return m_dir;
	}

	void CSnake::setLength(TypeLength length)
	{
		m_length = length;
	}

	CSnake::TypeMoveDir CSnake::getLength()
	{
		return m_length;
	}

	bool CSnake::move()
	{
		bool flag;
		moveBody();
		flag = moveHead();
		return flag;
	}

	bool CSnake::growMove()
	{
		bool flag;
		CImagePoint temp(m_body[0].getCX(), m_body[0].getCY(), cm_defaultBodyShape, cm_defaultColor);

		//Update the coordinate of Snake's head(A absolute coordinate in CGameElementObject)
		flag = moveHead();

		m_body.insert(m_body.begin() + 1, temp);
		return flag;
	}

	std::vector<CImagePoint> CSnake::getImage()
	{
		return this->m_body;
	}

	bool CSnake::moveHead()
	{
		bool flag = true;

		//Update the coordinate of Snake's head(A absolute coordinate in CGameElementObject)
		switch (m_dir)
		{
		case DIR_UP:
			//coordinate in CGameElementObeject is absolute!

			//Move the ElementObject's coordinate
			moveUp();
			//Move the ImagePoint's coordinate
			m_body[0].moveUp();
			break;

		case DIR_DOWN:
			//Move the ElementObject's coordinate
			moveDown();
			//Move the ImagePoint's coordinate
			m_body[0].moveDown();

			break;

		case DIR_LEFT:
			//Move the ElementObject's coordinate
			moveLeft();
			//Move the ImagePoint's coordinate
			m_body[0].moveLeft();

			break;

		case DIR_RIGHT:
			//Move the ElementObject's coordinate
			moveRight();
			//Move the ImagePoint's coordinate
			m_body[0].moveRight();

			break;

		default://the default case is DIR_LEFT
				//Move the ElementObject's coordinate
			moveLeft();
			//Move the ImagePoint's coordinate
			m_body[0].moveLeft();
			break;
		}

		int counter = 0;
		for (auto elm : m_body)
		{
			if (m_body[0].getCX() == elm.getCX() &&
				m_body[0].getCY() == elm.getCY())
				++counter;
		}
		if (counter > 1)
			flag = false;
		return flag;
	}

	void CSnake::moveBody()
	{
		//Update the coordinate of Snake's body.
		//Didn't change the head of the index.
		for (int index = (int)(m_body.size()) - 1; index > 0; --index)
		{
			m_body[index].setCX(m_body[index - 1].getCX());
			m_body[index].setCY(m_body[index - 1].getCY());
		}
	}



}
