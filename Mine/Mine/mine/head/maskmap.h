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
/*	��ʼ���ڸǲ�
*
*	@map	�ڸǲ�ĵ�ַ
*	@row	�ڸǲ������
*	@col	�ڸǲ������
*
*	@return
*/
/************************************************************************/
void MaskMap_init(MaskMap * maskMap, int row, int col);

#endif

