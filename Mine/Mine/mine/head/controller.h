#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "tool.h"
#include "controllerMessage.h"
#include "minemap.h"



/************************************************************************/
/*	从键盘得到按下的按键
 *
 *	@map	地图
 *
 *	@return 根据键盘那的按下的情况, 并返回控制消息块
*/
/************************************************************************/
ContolMessage GetControlMessage(const MineMap * map);

#endif // CONTROLLER_H_
