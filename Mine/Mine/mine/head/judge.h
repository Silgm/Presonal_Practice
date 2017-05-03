#ifndef JUDGE_H_
#define JUDGE_H_

#include "controllerMessage.h"
#include "judgeMessage.h"
#include "minemap.h"
#include "maskmap.h"

/************************************************************************/
/* 
 *	对输入的cmsg和map进行裁判, 在jmsg_out中的改变场地
 *
 *
 *	@map			地图信息
 *	@maskmap		遮蔽层信息
 *	@cmsg			接受来自控制器control的控制信息
 *	@return			返回裁判消息块
*/
/************************************************************************/
JudgeMessage Judge(const MineMap * map, MaskMap * maskmap, const ContolMessage cmsg);



#endif
