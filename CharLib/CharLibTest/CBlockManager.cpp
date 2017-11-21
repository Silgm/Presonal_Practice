#include "CBlockManager.h"



namespace gm {
	CBlockManager::CBlockManager()
	{
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
		this->blockGroup.push_back(CBlock());
	}
	void CBlockManager::freezeActive()
	{
		this->getActiveBlockRef().freeze();
		this->addActive();
	}
	void CBlockManager::moveDropActive()
	{
		std::unique_lock<std::mutex> lock(this->mut);
		if (this->canDrop())
			this->getActiveBlockRef().drop();
		else
		{
			freezeActive();
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
	CBlock & CBlockManager::getActiveBlockRef()
	{
		// TODO: 在此处插入 return 语句
		return this->blockGroup[this->blockGroup.size() - 1];
	}
}