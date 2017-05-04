#include "../head/renderer.h"



void Render(const InterfaceData * interfacemap, InterfaceMessage imsg)
{
	HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	if (imsg.reflash == true) {
		if (imsg.state == INTERFACE_STATE_RUN) {
			position.X = 0;
			position.Y = 0;
			SetConsoleCursorPosition(hCmd, position);
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
		}
		else if (imsg.state == INTERFACE_STATE_END_FAIL) {

		}
		else if (imsg.state == INTERFACE_STATE_END_WIN) {

		}
	}
	position.X = 2*imsg.pos.y;
	position.Y = imsg.pos.x;
	SetConsoleCursorPosition(hCmd, position);
}
