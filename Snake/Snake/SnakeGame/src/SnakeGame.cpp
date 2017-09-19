#include "SnakeGame.h"



//code about game
int sg::SnakeGame_Start(int args, char *argv[]) {
	std::cout << "Hello" << std::endl;
	
	CSnake snake(0, 0, CSnake::EnumMoveDir::DIR_RIGHT, 3);

	return EXIT_SUCCESS;
}


