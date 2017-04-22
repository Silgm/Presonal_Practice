#ifndef MINEMAP_H_
#define MINEMAP_H_

#include "tool.h"

#define MAX_LEN		127
#define MAX_WID		127

typedef enum _block {
	BLOCK_0 = '0',
	BLOCK_1	= '1',
	BLOCK_2 = '2',
	BLOCK_3 = '3',
	BLOCK_4	= '4',
	BLOCK_5	= '5',
	BLOCK_6 = '6',
	BLOCK_7	= '7',
	BLOCK_8 = '8',
	BLOCK_MINE = '*',
	BLOCK_FLAG = '^'
}Block;

typedef struct _minemap
{
	Block map[MAX_LEN][MAX_WID];
	int mineNums;
	int row;
	int col;
}MineMap;

/************************************************************************/
/*	初始化地图
 *
 *	@map	地图MineMap的地址
 *	@row	地图的行数
 *	@col	地图的列数
 *	@mine	雷的个数
 *
 *	@return 
*/
/************************************************************************/
void MineMap_init(MineMap * map, int row, int col, int mine);

#endif // !MINEMAP_H_
