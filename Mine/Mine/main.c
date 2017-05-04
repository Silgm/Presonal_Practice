#include "main.h"
#define MAXTEMP_LEN	64
int main() {
	ContolMessage cmsg;
	JudgeMessage jmsg;
	InterfaceMessage imsg;

	HANDLE hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
	MaskMap maskmap;
	MineMap minemap;
	InterfaceData infmap;

	int inputRow, inputCol, inputMineNums;
	char temp[MAXTEMP_LEN];
	jmsg.gameState = GAMESTATE_RUN;
	jmsg.refresh = true;
	SetConsoleTitle(L"大哥的扫雷");
	setlocale(LC_ALL, "");

	wprintf(L">>请输入地图高度(<64):");
	scanf_s("%d", &inputRow);
	wprintf(L">>请输入地图长度(<64):");
	scanf_s("%d", &inputCol);
	wprintf(L">>请输入雷的个数:");
	scanf_s("%d", &inputMineNums);
	system("cls");
	for (int indexI = 0; indexI < 3; indexI++) {
		wprintf(L"游戏即将开始!");
		wprintf(L"Wait:%d", 3 - indexI);
		Sleep(1000);
		system("cls");
	}
	system("cls");
	
	sprintf_s(temp, sizeof(temp),"mode con cols=%d lines=%d", inputCol*2 + 5, inputRow+5);
	system(temp);
	MineMap_init(&minemap, inputRow, inputCol, inputMineNums);
	MaskMap_init(&maskmap, minemap.row, minemap.col);
	jmsg.minenums = minemap.mineNums;
	imsg = InterfaceMake(&minemap, &maskmap, jmsg, &infmap);
	Render(&infmap, imsg);

	do {
		cmsg = GetControlMessage(&minemap);/*控制器需要通过minemap的信息来控制, 光标的最大位置*/
		jmsg = Judge(&minemap, &maskmap, cmsg);
		imsg = InterfaceMake(&minemap, &maskmap, jmsg, &infmap);
		Render(&infmap, imsg);
	} while (cmsg.key != KEY_ESC && jmsg.gameState == GAMESTATE_RUN);
	
	SetConsoleTextAttribute(hCmd, COLOR_LYELLOW);

	if (jmsg.gameState == GAMESTATE_WIN) {
		wprintf(L"你赢了!游戏结束!\n");
	}
	else {
		wprintf(L"你输了!游戏结束!\n");
	}
	system("pause");

	return EXIT_SUCCESS;
}


