#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "tool.h"
#include "controllerMessage.h"
#include "minemap.h"



/************************************************************************/
/*	�Ӽ��̵õ����µİ���
 *
 *	@map	��ͼ
 *
 *	@return ���ݼ����ǵİ��µ����, �����ؿ�����Ϣ��
*/
/************************************************************************/
ContolMessage GetControlMessage(const MineMap * map);

#endif // CONTROLLER_H_
