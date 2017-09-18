#ifndef _SNAKEGAME_H_
#define _SNAKEGAME_H_

//! 所有游戏有关的类与函数全部在sg名字空间内, sg表示Sanke Game
//游戏本体的类
#include "SnakeGame_class.h"


namespace sg {
	//游戏入口
	int SnakeGame_Start(int args, char *argv[]);

}




#endif


