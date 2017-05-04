#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "judgeMessage.h"
#include "interfaceMessage.h"

InterfaceMessage InterfaceMake(const MineMap *minemap, const MaskMap *maskmap, JudgeMessage jmsg, InterfaceData *_out_interfacedata);


#endif

