#include "CBlockManager.h"



namespace gm {
	CBlockManager::CBlockManager(int height, int width)
	{
		this->maxHeight = height;
		this->maxWidth = width;
		this->addActive();
	}

	CBlockManager::~CBlockManager()
	{

	}

	const cl::CLImgPoint::imgPointGroup_type& CBlockManager::getImageGroup() const
	{
		// TODO: 在此处插入 return 语句
		return imgGroup;
	}

	void CBlockManager::flash()
	{
		std::unique_lock<std::mutex> lock(this->mut);
		imgGroup.clear();
		for (const auto &elm : this->blockGroup)
		{
			imgGroup.insert(imgGroup.end(), elm.getImageGroup().begin(), elm.getImageGroup().end());
		}
		lock.unlock();
	}

	void CBlockManager::addActive()
	{
		if (this->canAdd())
			this->blockGroup.push_back(CBlock());
	}

	void CBlockManager::freezeActive()
	{
		this->getActiveBlockRef().freeze();
		this->addActive();
	}

	void CBlockManager::dropToEndActive()
	{
		while (this->canDrop())
			this->dropActive();
		this->dropActive();
	}

	bool CBlockManager::isEnd()
	{
		return this->isStop;
	}

	void CBlockManager::dropActive()
	{
		std::unique_lock<std::mutex> lock(this->mut);
		if (this->canDrop())
			this->getActiveBlockRef().drop();
		else
		{
			freezeActive();
			if (this->isGoodLine())
			{

			}
		}
		lock.unlock();
	}

	void CBlockManager::moveLeftActive()
	{
		std::unique_lock<std::mutex> lock(this->mut);
		if (this->canLeft())
			this->getActiveBlockRef().left();
		lock.unlock();
	}

	void CBlockManager::moveRightActive()
	{
		std::unique_lock<std::mutex> lock(this->mut);
		if (this->canRight())
			this->getActiveBlockRef().right();
		lock.unlock();
	}

	void CBlockManager::changeActive()
	{
		std::unique_lock<std::mutex> lock(this->mut);
		if (this->canChange())
			this->getActiveBlockRef().change();
		lock.unlock();
	}

	bool CBlockManager::canDrop()
	{
		CBlock newBlock(this->getActiveBlockRef());
		newBlock.drop();
		//判断有有没有达到低端
		for (const auto& elm : newBlock.getImageGroup())
		{
			if (elm.getCY() >= this->maxHeight)
			{
				return false;
			}
		}

		//判断有没有相撞
		for (auto it = this->imgGroup.cbegin(); it < imgGroup.cend() - 4; ++it)
		{
			for (const auto& elm : newBlock.getImageGroup())
			{ 
				if (elm.getCX() == it->getCX() && elm.getCY() == it->getCY())
				{
					return false;
				}
			}
		}
		return true;
	}

	bool CBlockManager::canLeft()
	{
		CBlock newBlock(this->getActiveBlockRef());
		newBlock.left();
		for (const auto& elm : newBlock.getImageGroup())
		{
			if (elm.getCX() < 0)
			{
				return false;
			}
		}

		for (auto it = this->imgGroup.cbegin(); it < imgGroup.cend() - 4; ++it)
		{
			for (const auto& elm : newBlock.getImageGroup())
			{
				if (elm.getCX() == it->getCX() && elm.getCY() == it->getCY())
				{
					return false;
				}
			}
		}
		return true;
	}

	bool CBlockManager::canRight()
	{
		CBlock newBlock(this->getActiveBlockRef());
		newBlock.right();
		for (const auto& elm : newBlock.getImageGroup())
		{
			if (elm.getCX() >= this->maxWidth)
			{
				return false;
			}
		}

		for (auto it = this->imgGroup.cbegin(); it < imgGroup.cend() - 4; ++it)
		{
			for (const auto& elm : newBlock.getImageGroup())
			{
				if (elm.getCX() == it->getCX() && elm.getCY() == it->getCY())
				{
					return false;
				}
			}
		}
		return true;
	}

	bool CBlockManager::canChange()
	{
		CBlock newBlock(this->getActiveBlockRef());
		newBlock.change();
		for (const auto& elm : newBlock.getImageGroup())
		{
			if (elm.getCX() >= this->maxWidth)
			{
				return false;
			}
		}

		for (const auto& elm : newBlock.getImageGroup())
		{
			if (elm.getCX() < 0)
			{
				return false;
			}
		}

		for (auto it = this->imgGroup.cbegin(); it < imgGroup.cend() - 4; ++it)
		{
			for (const auto& elm : newBlock.getImageGroup())
			{
				if (elm.getCX() == it->getCX() && elm.getCY() == it->getCY())
				{
					return false;
				}
			}
		}
		return true;
	}

	bool CBlockManager::canAdd()
	{
		CBlock newBlock;
		if (!this->imgGroup.empty())
		{
			for (const auto& elm : newBlock.getImageGroup())
			{
				if (elm.getCX() >= this->maxWidth)
				{
					this->isStop = true;
					return false;
				}
			}

			for (const auto& elm : newBlock.getImageGroup())
			{
				if (elm.getCX() < 0)
				{
					this->isStop = true;
					return false;
				}
			}

			for (auto it = this->imgGroup.cbegin(); it < imgGroup.cend() - 4; ++it)
			{
				for (const auto& elm : newBlock.getImageGroup())
				{
					if (elm.getCX() == it->getCX() && elm.getCY() == it->getCY())
					{
						this->isStop = true;
						return false;
					}
				}
			}
		}
		return true;
	}

	bool CBlockManager::isGoodLine()
	{
		return false;
	}

	CBlock& CBlockManager::getActiveBlockRef()
	{
		return this->blockGroup[this->blockGroup.size() - 1];
	}
}