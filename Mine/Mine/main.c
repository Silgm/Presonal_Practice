#include "main.h"

int main() {
	ContolMessage cmsg;
	JudgeMessage jmsg;
	InterfaceMessage imsg;
	
	MaskMap maskmap;
	MineMap minemap;
	InterfaceData infmap;

	jmsg.gameState = GAMESTATE_RUN;
	jmsg.refresh = true;
	MineMap_init(&minemap, 22, 30, 99);
	MaskMap_init(&maskmap, minemap.row, minemap.col);
	imsg = InterfaceMake(&minemap, &maskmap, jmsg, &infmap);
	Render(&infmap, imsg);

	do {
		cmsg = GetContolMessage(&minemap);/*控制器需要通过minemap的信息来控制, 光标的最大位置*/
		jmsg = Judge(&minemap, &maskmap, cmsg);
		imsg = InterfaceMake(&minemap, &maskmap, jmsg, &infmap);
		Render(&infmap, imsg);
	} while (cmsg.key != KEY_ESC);

	return EXIT_SUCCESS;
}



// 
// int main() {
// 	MineMap map;
// 	ContolMessage cmsg;
// 	MineMap_init(&map, 10, 10, 10);
// 	while (1) {
// 		cmsg = GetKey(&map);
// 		
// 	}
// 	return EXIT_SUCCESS;
// }

//int main() {
//	MineMap map;
//	ContolMessage cmsg;
//	MineMap_init(&map, 20, 30, 20);
//	for (int indexI = 0; indexI < map.row; indexI++) {
//		for (int indexJ = 0; indexJ < map.col; indexJ++) {
//			printf("%c ", map.map[indexI][indexJ]);
//		}
//		puts("");
//	}
//	while (1) {
//		cmsg = GetContolMessage(&map);
//	}
//	return EXIT_SUCCESS;
//}


