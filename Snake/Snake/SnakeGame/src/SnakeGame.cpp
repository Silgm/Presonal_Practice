#include "SnakeGame.h"

constexpr sg::CGameElementObject::TypeCoordinate DEFAULT_X_WIDTH = 20;
constexpr sg::CGameElementObject::TypeCoordinate DEFAULT_Y_WIDTH = 20;
constexpr sg::CGameElementObject::TypeCoordinate SLEEP_TIME = 250;

int score = 0;

int sg::SnakeGame_Start(int args, char *argv[]) {
	int newKey = 0, lastKey = 0;
	int newCurtKey = 0, oldCurtKey = 0;

	
	//Game System Class
	CSysClock clk;
	CSysController ctrl;
	CSysInterface intface(DEFAULT_X_WIDTH, DEFAULT_Y_WIDTH);

	//Game Element Class 
	CSnake snake(10, 10, CSnake::EnumMoveDir::DIR_DOWN, 4);
	CFood food(DEFAULT_X_WIDTH, DEFAULT_Y_WIDTH);
	CWall wall(DEFAULT_X_WIDTH, DEFAULT_Y_WIDTH);

	clk.start();
	do {
		//last key
		newKey = ctrl.getKeyCurt();
		if (newKey != -1)
			newCurtKey = newKey;

		if (clk.getTime_fromStart() > SLEEP_TIME)
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


			if (snake.getCX() == food.getCX() && snake.getCY() == food.getCY())
			{
				++score;
				food.reFlash();
				intface.addImage(food.getImage());
				if (snake.growMove() && intface.addImage(snake.getImage()))//if return false, the snake crash itself
				{
					intface.addImage(wall.getImage());
					intface.render();
					intface.clearBuff();

					HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
					COORD position;
					position.X = 0;
					position.Y = 25;
					SetConsoleCursorPosition(hCmd, position);
					printf("当前得分:%d\n", score);
				}
				else
				{
					intface.clearBuff();
					break;
				}
			}
			else
			{
				intface.addImage(food.getImage());
				if (snake.move() && intface.addImage(snake.getImage()))//if return false, the snake crash itself
				{
					intface.addImage(wall.getImage());
					intface.render();
					intface.clearBuff();
					HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
					COORD position;
					position.X = 0;
					position.Y = 25;
					SetConsoleCursorPosition(hCmd, position);
					printf("当前得分:%d\n", score);
				}
				else
				{
					intface.clearBuff();
					break;
				}
			}
		}

	} while (newCurtKey != CSysController::EnumKey::KEY_ESC);

	system("cls");
	printf("游戏结束\n");
	return EXIT_SUCCESS;
}


