#ifndef JUDGE_H_
#define JUDGE_H_

#include "controllerMessage.h"
#include "judgeMessage.h"
#include "minemap.h"
#include "maskmap.h"

/************************************************************************/
/* 
 *	�������cmsg��map���в���, ��jmsg_out�еĸı䳡��
 *
 *
 *	@map			��ͼ��Ϣ
 *	@maskmap		�ڱβ���Ϣ
 *	@cmsg			�������Կ�����control�Ŀ�����Ϣ
 *	@return			���ز�����Ϣ��
*/
/************************************************************************/
JudgeMessage Judge(const MineMap * map, MaskMap * maskmap, const ContolMessage cmsg);



#endif
