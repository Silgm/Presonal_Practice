#include "../head/maskmap.h"

void MaskMap_init(MaskMap * maskMap, int row, int col){
	for (int indexI = 0; indexI < row; indexI++) {
		for (int indexJ = 0; indexJ < col; indexJ++) {
			maskMap->map[indexI][indexJ] = MASKSTATE_INVISIBLE;
		}
	}
}

