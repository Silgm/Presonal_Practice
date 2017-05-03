#ifndef TOOL_H_
#define TOOL_H_
/************************************************************************/
/* 
 *tool.h
 *
 *some normal function and marco define 
*/
/************************************************************************/


#include <assert.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <wchar.h>
#include <windows.h>

//地图最大长度(row)
#define MAX_LEN		64

//地图最大宽度(col)
#define MAX_WID		64

/************************************************************************/
/**
*	生成一个0~1之间的double类型的随机数
*
*	@return		一个0~1之间的double类型的随机数
*/
/************************************************************************/
double random();



#endif
