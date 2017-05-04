#ifndef INTERFACE_MESSAGE_H_
#define INTERFACE_MESSAGE_H_

#include "minemap.h"
#include "maskmap.h"

typedef enum _interface_block
{
	INTERFACE_BLOCK_0 = '0',
	INTERFACE_BLOCK_1 = '1',
	INTERFACE_BLOCK_2 = '2',
	INTERFACE_BLOCK_3 = '3',
	INTERFACE_BLOCK_4 = '4',
	INTERFACE_BLOCK_5 = '5',
	INTERFACE_BLOCK_6 = '6',
	INTERFACE_BLOCK_7 = '7',
	INTERFACE_BLOCK_8 = '8',
	INTERFACE_BLOCK_MINE = '*',
	INTERFACE_BLOCK_FLAG = '^',
	INTERFACE_BLOCK_VISUAL = ' ',
	INTERFACE_BLOCK_INVISUAL = '-'
}InterfaceBlock;

typedef struct _interface_data {
	InterfaceBlock interfaceMap[MAX_LEN][MAX_WID];
}InterfaceData;

typedef struct _interface_message{
	
}InterfaceMsg;

#endif
