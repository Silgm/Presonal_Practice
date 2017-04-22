#include "../head/minemap.h"

void MineMap_init(MineMap * map, int row, int col, int mine)
{
	map->row = row > MAX_LEN ? (MAX_LEN) : row;
	map->col = col > MAX_WID ? (MAX_LEN) : col;
	map->mineNums = mine;
	for (; mine; mine--) {
		map->map[(int)(map->row * random())][(int)(map->col * random())] = BLOCK_MINE;
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
				if (i + 1 < map->row && j - 1 > 0 && map->map[i + 1][j - 1] == BLOCK_MINE)
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
