#include "../head/controller.h"

ContolMessage GetContolMessage(const MineMap * map) {
	static int posX = 0, posY = 0;
	//static char flag = 1;
	//HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD position;
	ContolMessage msg;
	//if (flag) {
	//	SetConsoleTitle(L"´ó¸çµÄÉ¨À×");
	//	flag = 0;
	//}
#if _MSC_VER >= 1900
	msg.key = _getch();
#else
	msg.key = getch();
#endif

	switch (msg.key) {

	case KEY_UP:
		posX > 0 && posX--;
		break;
	case KEY_DOWN:
		posX < map->row - 1 && posX++;
		break;
	case KEY_LEFT:
		posY > 0 && posY--;
		break;
	case KEY_RIGHT:
		posY < map->col - 1 && posY++;
		break;
	case KEY_ESC:
		exit(EXIT_SUCCESS);
		break;
	default:
		break;

	}

	msg.pos.x = posX;
	msg.pos.y = posY;

	//position.X = 2*msg.pos.y;
	//position.Y = msg.pos.x;

	//SetConsoleCursorPosition(hCmd, position);

	return msg;
}
