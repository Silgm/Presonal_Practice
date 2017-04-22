#include "main.h"


int main() {
	MineMap map;
	ContolMessage cmsg;
	MineMap_init(&map, 10, 10, 10);
	while (1) {
		cmsg = GetKey(&map);
		
	}
	return EXIT_SUCCESS;
}

