#ifndef _CBLOCKMANAGER_H_
#define _CBLOCKMANAGER_H_

#include "CBlock.h"

namespace gm {
	class CBlockManager 
	{
	public:
		CBlockManager();
		virtual ~CBlockManager();

		const cl::CLImgPoint::imgPointGroup_type& getImageGroup() const;	//与Interface交互的部分
		void flash();



		void moveDropActive();
		void moveLeftActive();
		void moveRightActive();
		void changeActive();
		void freezeActive();


	private:
		std::vector<CBlock> blockGroup;
		cl::CLImgPoint::imgPointGroup_type imgGroup;
		void addActive();
		bool canDrop();
		bool canLeft();
		bool canRight();
		bool canChange();
		CBlock& getActiveBlockRef();
		std::mutex mut;
	};
}

#endif
