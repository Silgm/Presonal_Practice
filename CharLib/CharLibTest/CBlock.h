#ifndef _CLBLOCK_H_
#define _CLBLOCK_H_

#include "CharLib.h"

namespace gm 
{
	class CBlock : public cl::CLElm
	{
	public :
		CBlock();
		virtual ~CBlock();
		void drop();
		void left();
		void right();
		void change();

		void freeze();

		const cl::CLImgPoint::imgPointGroup_type& getImageGroup() const;

	private:
		bool	isFreeze = false;
		int		changeTime = 3;
		/*
		 * ����		blockTypeֵ
		 
		 * ����		0
		 * ����		1
		 * ��L		2
		 * ��L		3
		 * T��		
		 * ��Z
		 * ��Z
		*/
		uint8_t blockType;
		cl::CLImgPoint::imgPointGroup_type imgGroup;

		void addBlockA();
		void addBlockB();
		void addBlockC();
		void addBlockD();
		void addBlockE();
		void addBlockF();
		void addBlockG();

		void blockChangeB(int times);
		void blockChangeC(int times);
		void blockChangeD(int times);
		void blockChangeE(int times);
		void blockChangeF(int times);
		void blockChangeG(int times);
	};
}

#endif
