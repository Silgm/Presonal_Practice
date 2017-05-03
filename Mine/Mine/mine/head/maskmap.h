#ifndef MASKMAP_H_
#define MASKMAP_H_

#include "tool.h"

typedef enum _MaskState {
	MASKSTATE_VISUAL = 0,
	MASKSTATE_INVISIBLE = 1,
	MASKSTATE_FLAG = 2
}MaskState;

typedef struct _MaskMap
{
	MaskState map[MAX_LEN][MAX_WID];
	int row;
	int col;
}MaskMap;

/************************************************************************/
/*	初始化遮盖层
*
*	@map	遮盖层的地址
*	@row	遮盖层的行数
*	@col	遮盖层的列数
*
*	@return
*/
/************************************************************************/
void MaskMap_init(MaskMap * maskMap, int row, int col);

#endif

