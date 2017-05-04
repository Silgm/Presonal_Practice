#include "../head/interface.h"

InterfaceMessage InterfaceMake(const MineMap * minemap, const MaskMap * maskmap, JudgeMessage jmsg, InterfaceData * _out_interfacedata) {
	InterfaceMessage imsg;
	
	_out_interfacedata->row = minemap->row;
	_out_interfacedata->col = minemap->col;

	imsg.reflash = jmsg.refresh;
	imsg.pos = jmsg.pos;
	imsg.minenums = jmsg.minenums;
	switch (jmsg.gameState)
	{
	case GAMESTATE_RUN:
		imsg.state = INTERFACE_STATE_RUN;
		for (int indexI = 0; indexI < minemap->row; indexI++) {
			for (int indexJ = 0; indexJ < minemap->col; indexJ++) {

				switch (maskmap->map[indexI][indexJ])
				{
				case MASKSTATE_INVISIBLE:
					_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_INVISUAL;
					break;
				case MASKSTATE_VISUAL:
					if (minemap->map[indexI][indexJ] == BLOCK_0) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_0;
					}
					else if (minemap->map[indexI][indexJ] >= BLOCK_1 && minemap->map[indexI][indexJ] <= BLOCK_8) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = minemap->map[indexI][indexJ];
					}
					else if (minemap->map[indexI][indexJ] == BLOCK_MINE) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_MINE;
					}
					break;
				case MASKSTATE_FLAG:
					_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_FLAG;
					break;
				default:
					break;
				}
			}
		}
		break;
	case GAMESTATE_FAIL:
		imsg.state = INTERFACE_STATE_END_FAIL;
		for (int indexI = 0; indexI < minemap->row; indexI++) {
			for (int indexJ = 0; indexJ < minemap->col; indexJ++) {
				switch (maskmap->map[indexI][indexJ])
				{
				case MASKSTATE_INVISIBLE:
					if (minemap->map[indexI][indexJ] != BLOCK_0)
						_out_interfacedata->interfaceMap[indexI][indexJ] = minemap->map[indexI][indexJ];
					else
						_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_0;
					break;
				case MASKSTATE_VISUAL:
					if (minemap->map[indexI][indexJ] == BLOCK_0) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_0;
					}
					else if (minemap->map[indexI][indexJ] >= BLOCK_1 && minemap->map[indexI][indexJ] <= BLOCK_8) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = minemap->map[indexI][indexJ];
					}
					else if (minemap->map[indexI][indexJ] == BLOCK_MINE) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_MINE;
					}
					break;
				case MASKSTATE_FLAG:
					_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_FLAG;
					break;
				default:
					break;
				}
			}
		}
		break;
	case GAMESTATE_WIN:
		imsg.state = INTERFACE_STATE_END_WIN;
		for (int indexI = 0; indexI < minemap->row; indexI++) {
			for (int indexJ = 0; indexJ < minemap->col; indexJ++) {
				switch (maskmap->map[indexI][indexJ])
				{
				case MASKSTATE_INVISIBLE:
					_out_interfacedata->interfaceMap[indexI][indexJ] = minemap->map[indexI][indexJ];
					break;
				case MASKSTATE_VISUAL:
					if (minemap->map[indexI][indexJ] == BLOCK_0) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_0;
					}
					else if (minemap->map[indexI][indexJ] >= BLOCK_1 && minemap->map[indexI][indexJ] <= BLOCK_8) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = minemap->map[indexI][indexJ];
					}
					else if (minemap->map[indexI][indexJ] == BLOCK_MINE) {
						_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_MINE;
					}
					break;
				case MASKSTATE_FLAG:
					_out_interfacedata->interfaceMap[indexI][indexJ] = INTERFACE_BLOCK_FLAG;
					break;
				default:
					break;
				}
			}
		}
		break;
	default:
		break;
	}
	return imsg;
}

