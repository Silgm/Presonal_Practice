#include "SnakeGame.h"


int sg::SnakeGame_Start(int args, char *argv[]) {
	int newKey = 0, lastKey = 0;
	int newCurtKey = 0, oldCurtKey = 0;
	int dir = 1;
	CSysClock clk;
	CSysController ctrl;
	CSysInterface intface(50, 50);
	CSnake snake(10, 10, CSnake::EnumMoveDir::DIR_DOWN, 8);


	clk.start();
	do {
		newKey = ctrl.getKeyCurt();
		if (newKey != -1)
			newCurtKey = newKey;

		if (clk.getTime_fromStart() > 250)
		{
			clk.start();

			switch (newCurtKey)
			{
			case CSysController::EnumKey::KEY_LEFT:
				snake.setDir(CSnake::EnumMoveDir::DIR_LEFT);
				break;

			case CSysController::EnumKey::KEY_RIGHT:
				snake.setDir(CSnake::EnumMoveDir::DIR_RIGHT);
				break;

			case CSysController::EnumKey::KEY_DOWN:
				snake.setDir(CSnake::EnumMoveDir::DIR_UP);
				break;

			case CSysController::EnumKey::KEY_UP:
				snake.setDir(CSnake::EnumMoveDir::DIR_DOWN);
				break;
			default:
				break;
			}

			if (snake.move())
			{
				intface.addImage(snake.getImage());
				intface.render();
				intface.clearBuff();
			}
			else
			{
				break;
			}


		}
	} while (newCurtKey != CSysController::EnumKey::KEY_ESC);

	system("cls");
	return EXIT_SUCCESS;
}


