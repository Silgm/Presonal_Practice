#include "../head/minemap.h"
/*扫雷地图初始化*/
/************************************************************************/
/*
包括行列初始化, 根据输入的雷数, 随机放雷, 根据雷放置周围的数字等等.
*/
/************************************************************************/


void MineMap_init(MineMap * map, int row, int col, int mine)
{
	map->row = row > MAX_LEN ? (MAX_LEN) : row;
	map->col = col > MAX_WID ? (MAX_LEN) : col;
	map->mineNums = mine;
	while (mine) {
		int posX = (int)(map->row * random()) % map->row;
		int posY = (int)(map->col * random()) % map->col;
		if (map->map[posX][posY] != BLOCK_MINE) {
			map->map[posX][posY] = BLOCK_MINE;
			mine--;
		}
	}
	for (int i = 0; i < map->row; i++) {
		for (int j = 0; j < map->col; j++) {
			if (map->map[i][j] != BLOCK_MINE) {
				map->map[i][j] = BLOCK_0;
			}
		}
	}
	for (int i = 0; i < map->row; i++) {
		for (int j = 0; j < map->col; j++) {
			if (map->map[i][j] != BLOCK_MINE) {
				int cnt = 0;

				if (i - 1 >= 0 && j - 1 >= 0 && map->map[i - 1][j - 1] == BLOCK_MINE)
					cnt++;
				if (j - 1 >= 0 && map->map[i][j - 1] == BLOCK_MINE)
					cnt++;
				if (i + 1 < map->row && j - 1 >= 0 && map->map[i + 1][j - 1] == BLOCK_MINE)
					cnt++;
				if (i - 1 >= 0 && map->map[i - 1][j] == BLOCK_MINE)
					cnt++;
				if (i + 1 < map->row && map->map[i + 1][j] == BLOCK_MINE)
					cnt++;
				if (i - 1 >= 0 && j + 1 < map->col && map->map[i - 1][j + 1] == BLOCK_MINE)
					cnt++;
				if (j + 1 < map->col && map->map[i][j + 1] == BLOCK_MINE)
					cnt++;
				if (i + 1 < map->row && j + 1 < map->col && map->map[i + 1][j + 1] == BLOCK_MINE)
					cnt++;

				map->map[i][j] = BLOCK_0 + cnt;
			}

		}
	}
}
