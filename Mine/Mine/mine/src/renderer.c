#include "../head/renderer.h"



void Render(const InterfaceData * interfacemap, InterfaceMessage imsg)
{
	HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	
	static char flag = 1;
	if (flag) {
		setlocale(LC_ALL, "");
		flag = 0;
	}

	if (imsg.reflash == true) {
		position.X = 0;
		position.Y = 0;
		SetConsoleCursorPosition(hCmd, position);
		SetConsoleTextAttribute(hCmd, COLOR_WHITE);
		for (int indexI = 0; indexI < interfacemap->row; indexI++) {
			for (int indexJ = 0; indexJ < interfacemap->col; indexJ++) {
				switch (interfacemap->interfaceMap[indexI][indexJ])
				{
				case INTERFACE_BLOCK_1:
					SetConsoleTextAttribute(hCmd, COLOR_LBLUE);
					break;
				case INTERFACE_BLOCK_2:
					SetConsoleTextAttribute(hCmd, COLOR_LGREEN);
					break;
				case INTERFACE_BLOCK_3:
					SetConsoleTextAttribute(hCmd, COLOR_LPURPLE);
					break;
				case INTERFACE_BLOCK_4:
					SetConsoleTextAttribute(hCmd, COLOR_LYELLOW);
					break;
				case INTERFACE_BLOCK_5:
					SetConsoleTextAttribute(hCmd, COLOR_LRED);
					break;
				case INTERFACE_BLOCK_6:
					SetConsoleTextAttribute(hCmd, COLOR_BWHITE);
					break;
				case INTERFACE_BLOCK_7:
					SetConsoleTextAttribute(hCmd, COLOR_GRAY);
					break;
				case INTERFACE_BLOCK_8:
					SetConsoleTextAttribute(hCmd, COLOR_LBGREEN);
					break;
				case INTERFACE_BLOCK_FLAG:
					SetConsoleTextAttribute(hCmd, COLOR_LRED);
					break;
				case INTERFACE_BLOCK_MINE:
					SetConsoleTextAttribute(hCmd, COLOR_LRED);
					break;
				default:
					break;
				}
				putchar(interfacemap->interfaceMap[indexI][indexJ]);
				SetConsoleTextAttribute(hCmd, COLOR_WHITE);
				putchar(' ');
			}
			putchar('|');
			putchar('\n');
		}
		for (int cnt = 0; cnt < interfacemap->col; cnt++) {
			printf("--");
		}
		putchar('\n');
		wprintf(L"提示:x开雷, z放置红旗, ESC键直接结束游戏.");
		wprintf(L"剩余雷数:%-10d\n", imsg.minenums);
	}
	if (imsg.state == INTERFACE_STATE_RUN) {

		position.X = 2*imsg.pos.y;
		position.Y = imsg.pos.x;
		SetConsoleCursorPosition(hCmd, position);
	}
}
