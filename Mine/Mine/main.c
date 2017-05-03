#include "main.h"

int main() {
	ContolMessage cmsg;
	JudgeMessage jmsg;
	MaskMap maskmap;
	MineMap minemap;

	MineMap_init(&minemap, 10, 10, 10);
	MaskMap_init(&maskmap, minemap.row, minemap.col);
	do {
		cmsg = GetContolMessage(&minemap);/*��������Ҫͨ��minemap����Ϣ������, �������λ��*/
		jmsg = Judge(&minemap, &maskmap, cmsg);
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


