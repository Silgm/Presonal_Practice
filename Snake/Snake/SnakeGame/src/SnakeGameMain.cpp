#include "SnakeGame.h"

int main(int args, char *argv[]) {

	int returnVal = EXIT_FAILURE;

	returnVal = sg::SnakeGame_Start(args, argv);

	system("pause");
	
	return returnVal;
}

