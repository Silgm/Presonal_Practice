#include "..\head\judge.h"

JudgeMessage Judge(const MineMap * map, MaskMap * maskmap, const ContolMessage cmsg)
{
	JudgeMessage jmsg;
	static current_flag_num = 0;

	jmsg.gameState = GAMESTATE_RUN;
	/*如果按下的是键盘X键*/
	if (cmsg.key == KEY_X && maskmap->map[cmsg.pos.x][cmsg.pos.y] == MASKSTATE_INVISIBLE) {
		/*如果选中的是数字方框*/
		if (map->map[cmsg.pos.x][cmsg.pos.y] > BLOCK_0 && map->map[cmsg.pos.x][cmsg.pos.y] <= BLOCK_8) {
			jmsg.gameState = GAMESTATE_RUN;
			maskmap->map[cmsg.pos.x][cmsg.pos.y] = MASKSTATE_VISUAL;
			return jmsg;
		}/*如果选中的是地雷砖块*/
		else if (map->map[cmsg.pos.x][cmsg.pos.y] == BLOCK_MINE) {
			jmsg.gameState = GAMESTATE_FAIL;
		}/*如果选中的是数字0方块*/
		else if (map->map[cmsg.pos.x][cmsg.pos.y] == BLOCK_0) {

			/*广度优先遍历*/

			CoordinateQueue *coordQueue;
			CoordinateQueue_new(&coordQueue);
			CoordinateQueue_en(coordQueue, cmsg.pos);

			while (!CoordinateQueue_isEmpty(coordQueue)){
				Coordinate coord = CoordinateQueue_de(coordQueue);
				if (maskmap->map[coord.x][coord.y] == MASKSTATE_INVISIBLE) {
					/*如果出队的是BLOCK_0方块的话,且遮蔽层为不可见,在mask中显示, 并且将上下左右的砖块也入队*/
					if (map->map[coord.x][coord.y] == BLOCK_0 ) {
						maskmap->map[coord.x][coord.y] = MASKSTATE_VISUAL;
						Coordinate coordtemp;
						if (coord.x - 1 >= 0) {							/*上方入队*/
							coordtemp.x = coord.x - 1;
							coordtemp.y = coord.y;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						else if (coord.x + 1 < map->row) {				/*下方入队*/
							coordtemp.x = coord.x + 1;
							coordtemp.y = coord.y;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						else if (coord.y - 1 >= 0) {					/*左方入队*/
							coordtemp.x = coord.x;
							coordtemp.y = coord.y - 1;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						else if (coord.y + 1 < map->col) {				/*右方入队*/
							coordtemp.x = coord.x;
							coordtemp.y = coord.y + 1;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
					}/*如果是数字砖块就显示,但不继续入队*/
					else if (map->map[coord.x][coord.y] >= BLOCK_0 && map->map[coord.x][coord.y] <= BLOCK_8) {
						maskmap->map[coord.x][coord.y] = MASKSTATE_VISUAL;
					}
				}
			}
			CoordinateQueue_free(&coordQueue);
		}
	}
	else if (cmsg.key == KEY_Z) {
		switch (maskmap->map[cmsg.pos.x][cmsg.pos.y])
		{
		case MASKSTATE_INVISIBLE:
			maskmap->map[cmsg.pos.x][cmsg.pos.y] = MASKSTATE_FLAG;
			break;
		case MASKSTATE_FLAG:
			maskmap->map[cmsg.pos.x][cmsg.pos.x] = MASKSTATE_INVISIBLE;
			break;
		default:
			break;
		}
	}
	return jmsg;
}
