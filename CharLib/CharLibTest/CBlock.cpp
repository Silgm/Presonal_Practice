#include "CBlock.h"

namespace gm 
{
	CBlock::CBlock()
		: cl::CLElm(2, 2)
	{
		switch (cl::random_int(0, 7))
		{
		case 0:
			this->addBlockA();
			blockType = 0;
			break;
		case 1:
			this->addBlockB();
			blockType = 1;
			break;
		case 2:
			this->addBlockC();
			blockType = 2;
			break;
		case 3:
			this->addBlockD();
			blockType = 3;
			break;
		case 4:
			this->addBlockE();
			blockType = 4;
			break;
		case 5:
			this->addBlockF();
			blockType = 5;
			break;
		case 6:
			this->addBlockG();
			blockType = 6;
			break;
		default:
			break;
		}
	}
	CBlock::~CBlock()
	{

	}
	void CBlock::drop()
	{
		if (!isFreeze)
		{
			this->moveDown();
			for (auto &elm : this->imgGroup)
			{
				elm.moveDown();
			}
		}
	}
	void CBlock::left()
	{
		if (!isFreeze)
		{
			this->moveLeft();
			for (auto &elm : this->imgGroup)
			{
				elm.moveLeft();
			}
		}

	}
	void CBlock::right()
	{
		if (!isFreeze)
		{
			this->moveRight();
			for (auto &elm : this->imgGroup)
			{
				elm.moveRight();
			}
		}
	}
	void CBlock::change()
	{
		++changeTime;
		changeTime = changeTime % 4;
		switch (this->blockType)
		{
		case 0:
			break;
		case 1:
			this->blockChangeB(changeTime);
			break;
		case 2:
			this->blockChangeC(changeTime);
			break;
		case 3:
			this->blockChangeD(changeTime);
			break;
		case 4:
			this->blockChangeE(changeTime);
			break;
		case 5:
			this->blockChangeF(changeTime);
			break;
		case 6:
			this->blockChangeG(changeTime);
			break;
		default:
			break;
		}
	}
	void CBlock::freeze()
	{
		this->isFreeze = true;
	}
	const cl::CLImgPoint::imgPointGroup_type& CBlock::getImageGroup() const
	{
		return this->imgGroup;
	}
	void CBlock::addBlockA()	//0 方块
	{
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY(), L'O', cl::CLImgPoint::COLOR_BWHITE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY() + 1, L'O', cl::CLImgPoint::COLOR_BWHITE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY() + 0, L'O', cl::CLImgPoint::COLOR_BWHITE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 0, this->getCY() + 1, L'O', cl::CLImgPoint::COLOR_BWHITE));
	}
	void CBlock::addBlockB()	//竖条
	{
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY(), L'O', cl::CLImgPoint::COLOR_LBGREEN));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() - 1, L'O', cl::CLImgPoint::COLOR_LBGREEN));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() + 1, L'O', cl::CLImgPoint::COLOR_LBGREEN));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() + 2, L'O', cl::CLImgPoint::COLOR_LBGREEN));
	}
	void CBlock::addBlockC()	//
	{
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY(), L'O', cl::CLImgPoint::COLOR_LGREEN));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() - 1, this->getCY(), L'O', cl::CLImgPoint::COLOR_LGREEN));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY(), L'O', cl::CLImgPoint::COLOR_LGREEN));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() - 1, this->getCY() + 1, L'O', cl::CLImgPoint::COLOR_LGREEN));
	}
	void CBlock::addBlockD()	//
	{
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY(), L'O', cl::CLImgPoint::COLOR_LPURPLE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() - 1, L'O', cl::CLImgPoint::COLOR_LPURPLE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() + 1, L'O', cl::CLImgPoint::COLOR_LPURPLE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY() - 1, L'O', cl::CLImgPoint::COLOR_LPURPLE));
	}
	void CBlock::addBlockE()	//T形
	{
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY(), L'O', cl::CLImgPoint::COLOR_LYELLOW));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() - 1, this->getCY(), L'O', cl::CLImgPoint::COLOR_LYELLOW));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY(), L'O', cl::CLImgPoint::COLOR_LYELLOW));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() + 1, L'O', cl::CLImgPoint::COLOR_LYELLOW));
	}
	void CBlock::addBlockF()	//反Z
	{
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY(), L'O', cl::CLImgPoint::COLOR_LRED));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() - 1, L'O', cl::CLImgPoint::COLOR_LRED));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY(), L'O', cl::CLImgPoint::COLOR_LRED));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY() + 1, L'O', cl::CLImgPoint::COLOR_LRED));
	}
	void CBlock::addBlockG()	//正Z
	{
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY(), L'O', cl::CLImgPoint::COLOR_LBLUE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() - 1, this->getCY() - 1, L'O', cl::CLImgPoint::COLOR_LBLUE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX(), this->getCY() - 1, L'O', cl::CLImgPoint::COLOR_LBLUE));
		imgGroup.push_back(cl::CLImgPoint(this->getCX() + 1, this->getCY(), L'O', cl::CLImgPoint::COLOR_LBLUE));
	}
	void CBlock::blockChangeB(int times)
	{
		switch (times)
		{
		case 0:
			for (auto &elm : this->imgGroup)
			{
				elm.setCoord(elm.getCX() + (elm.getCY() - this->getCY()), this->getCY());
			}
			break;
		case 1:
			for (auto &elm : this->imgGroup)
			{
				elm.setCoord(this->getCX(), elm.getCY() + (elm.getCX() - this->getCX()));
			}
			break;
		case 2:
			for (auto &elm : this->imgGroup)
			{
				elm.setCoord(elm.getCX() + (elm.getCY() - this->getCY()), this->getCY());
			}
			break;
		case 3:
			for (auto &elm : this->imgGroup)
			{
				elm.setCoord(this->getCX(), elm.getCY() + (elm.getCX() - this->getCX()));
			}
			break;
		default:
			break;
		}
	}
	void CBlock::blockChangeC(int times)
	{
		switch (times)
		{
		case 0:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(elm.getCX() + (elm.getCY() - this->getCY()), this->getCY());
				else if (distance == 2)
					elm.setCoord(elm.getCX() + 2, elm.getCY());
			}
			break;
		case 1:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(this->getCX(), elm.getCY() + (elm.getCX() - this->getCX()));
				else if (distance == 2)
					elm.setCoord(elm.getCX(), elm.getCY() - 2);
			}
			break;
		case 2:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(elm.getCX() + (elm.getCY() - this->getCY()), this->getCY());
				else if (distance == 2)
					elm.setCoord(elm.getCX() - 2, elm.getCY());
			}
			break;
		case 3:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(this->getCX(), elm.getCY() + (elm.getCX() - this->getCX()));
				else if (distance == 2)
					elm.setCoord(elm.getCX(), elm.getCY() + 2);
			}
			break;
		default:
			break;
		}
	}
	void CBlock::blockChangeD(int times)
	{
		switch (times)
		{
		case 0:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(elm.getCX() + (elm.getCY() - this->getCY()), this->getCY());
				else if (distance == 2)
					elm.setCoord(elm.getCX() - 2, elm.getCY());
			}
			break;
		case 1:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(this->getCX(), elm.getCY() + (elm.getCX() - this->getCX()));
				else if (distance == 2)
					elm.setCoord(elm.getCX(), elm.getCY() + 2);
			}
			break;
		case 2:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(elm.getCX() + (elm.getCY() - this->getCY()), this->getCY());
				else if (distance == 2)
					elm.setCoord(elm.getCX() + 2, elm.getCY());
			}
			break;
		case 3:
			for (auto &elm : this->imgGroup)
			{
				int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
				if (distance == 1)
					elm.setCoord(this->getCX(), elm.getCY() + (elm.getCX() - this->getCX()));
				else if (distance == 2)
					elm.setCoord(elm.getCX(), elm.getCY() - 2);
			}
			break;
		default:
			break;
		}
	}
	void CBlock::blockChangeE(int times)
	{
		for (auto &elm : this->imgGroup)
		{
			int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
			if (elm.getCX() > this->getCX() && elm.getCY() == this->getCY())
			{
				elm.setCoord(elm.getCX() - distance, elm.getCY() - distance);
			}
			else if (elm.getCX() == this->getCX() && elm.getCY() < this->getCY())
			{
				elm.setCoord(elm.getCX() - distance, elm.getCY() + distance);
			}
			else if (elm.getCX() < this->getCX() && elm.getCY() == this->getCY())
			{
				elm.setCoord(elm.getCX() + distance, elm.getCY() + distance);
			}
			else if (elm.getCX() == this->getCX() && elm.getCY() > this->getCY())
			{
				elm.setCoord(elm.getCX() + distance, elm.getCY() - distance);
			}
		}
	}
	void CBlock::blockChangeF(int times)
	{
		for (auto &elm : this->imgGroup)
		{
			int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
			if (distance == 1)
			{
				if (elm.getCX() > this->getCX() && elm.getCY() == this->getCY())
				{
					elm.setCoord(elm.getCX() - 1, elm.getCY() - 1);
				}
				else if (elm.getCX() == this->getCX() && elm.getCY() < this->getCY())
				{
					elm.setCoord(elm.getCX() - 1, elm.getCY() + 1);
				}
				else if (elm.getCX() < this->getCX() && elm.getCY() == this->getCY())
				{
					elm.setCoord(elm.getCX() + 1, elm.getCY() + 1);
				}
				else if (elm.getCX() == this->getCX() && elm.getCY() > this->getCY())
				{
					elm.setCoord(elm.getCX() + 1, elm.getCY() - 1);
				}
			}
			else if (distance == 2)
			{
				if (elm.getCX() > this->getCX() && elm.getCY() > this->getCY())
				{
					elm.setCoord(elm.getCX(), elm.getCY() - 2);
				}
				else if (elm.getCX() > this->getCX() && elm.getCY() < this->getCY())
				{
					elm.setCoord(elm.getCX() - 2, elm.getCY());
				}
				else if (elm.getCX() < this->getCX() && elm.getCY() < this->getCY())
				{
					elm.setCoord(elm.getCX(), elm.getCY() + 2);
				}
				else if (elm.getCX() < this->getCX() && elm.getCY() > this->getCY())
				{
					elm.setCoord(elm.getCX() + 2, elm.getCY());
				}
			}
		}
	}
	void CBlock::blockChangeG(int times)
	{
		for (auto &elm : this->imgGroup)
		{
			int distance = labs(elm.getCX() - this->getCX()) + labs(elm.getCY() - this->getCY());
			if (distance == 1)
			{
				if (elm.getCX() > this->getCX() && elm.getCY() == this->getCY())
				{
					elm.setCoord(elm.getCX() - 1, elm.getCY() - 1);
				}
				else if (elm.getCX() == this->getCX() && elm.getCY() < this->getCY())
				{
					elm.setCoord(elm.getCX() - 1, elm.getCY() + 1);
				}
				else if (elm.getCX() < this->getCX() && elm.getCY() == this->getCY())
				{
					elm.setCoord(elm.getCX() + 1, elm.getCY() + 1);
				}
				else if (elm.getCX() == this->getCX() && elm.getCY() > this->getCY())
				{
					elm.setCoord(elm.getCX() + 1, elm.getCY() - 1);
				}
			}
			else if (distance == 2)
			{
				if (elm.getCX() > this->getCX() && elm.getCY() > this->getCY())
				{
					elm.setCoord(elm.getCX(), elm.getCY() - 2);
				}
				else if (elm.getCX() > this->getCX() && elm.getCY() < this->getCY())
				{
					elm.setCoord(elm.getCX() - 2, elm.getCY());
				}
				else if (elm.getCX() < this->getCX() && elm.getCY() < this->getCY())
				{
					elm.setCoord(elm.getCX(), elm.getCY() + 2);
				}
				else if (elm.getCX() < this->getCX() && elm.getCY() > this->getCY())
				{
					elm.setCoord(elm.getCX() + 2, elm.getCY());
				}
			}
		}
	}
}
