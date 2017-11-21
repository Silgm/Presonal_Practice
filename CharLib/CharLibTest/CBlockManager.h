#ifndef _CBLOCKMANAGER_H_
#define _CBLOCKMANAGER_H_

#include "CBlock.h"

namespace gm {
	class CBlockManager 
	{
	public:
		CBlockManager(int height, int width);
		virtual ~CBlockManager();

		const cl::CLImgPoint::imgPointGroup_type& getImageGroup() const;	//与Interface交互的部分
		void flash();

		void dropActive();
		void moveLeftActive();
		void moveRightActive();
		void changeActive();
		void freezeActive();
		void dropToEndActive();
		bool isEnd();

	private:
		std::vector<CBlock> blockGroup;
		cl::CLImgPoint::imgPointGroup_type imgGroup;

		void addActive();
		bool canDrop();
		bool canLeft();
		bool canRight();
		bool canChange();
		bool canAdd();
		bool isGoodLine();
		CBlock& getActiveBlockRef();
		std::mutex mut;

		bool isStop = false;

		int maxHeight;
		int maxWidth;
	};
}

#endif
