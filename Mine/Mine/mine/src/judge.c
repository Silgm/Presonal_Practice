#include "..\head\judge.h"

JudgeMessage Judge(const MineMap * map, MaskMap * maskmap, const ContolMessage cmsg)
{
	JudgeMessage jmsg;
	static current_flag_num = 0;

	jmsg.gameState = GAMESTATE_RUN;
	/*������µ��Ǽ���X��*/
	if (cmsg.key == KEY_X && maskmap->map[cmsg.pos.x][cmsg.pos.y] == MASKSTATE_INVISIBLE) {
		/*���ѡ�е������ַ���*/
		if (map->map[cmsg.pos.x][cmsg.pos.y] > BLOCK_0 && map->map[cmsg.pos.x][cmsg.pos.y] <= BLOCK_8) {
			jmsg.gameState = GAMESTATE_RUN;
			maskmap->map[cmsg.pos.x][cmsg.pos.y] = MASKSTATE_VISUAL;
			return jmsg;
		}/*���ѡ�е��ǵ���ש��*/
		else if (map->map[cmsg.pos.x][cmsg.pos.y] == BLOCK_MINE) {
			jmsg.gameState = GAMESTATE_FAIL;
		}/*���ѡ�е�������0����*/
		else if (map->map[cmsg.pos.x][cmsg.pos.y] == BLOCK_0) {

			/*������ȱ���*/

			CoordinateQueue *coordQueue;
			CoordinateQueue_new(&coordQueue);
			CoordinateQueue_en(coordQueue, cmsg.pos);

			while (!CoordinateQueue_isEmpty(coordQueue)){
				Coordinate coord = CoordinateQueue_de(coordQueue);
				if (maskmap->map[coord.x][coord.y] == MASKSTATE_INVISIBLE) {
					/*������ӵ���BLOCK_0����Ļ�,���ڱβ�Ϊ���ɼ�,��mask����ʾ, ���ҽ��������ҵ�ש��Ҳ���*/
					if (map->map[coord.x][coord.y] == BLOCK_0 ) {
						maskmap->map[coord.x][coord.y] = MASKSTATE_VISUAL;
						Coordinate coordtemp;
						if (coord.x - 1 >= 0) {							/*�Ϸ����*/
							coordtemp.x = coord.x - 1;
							coordtemp.y = coord.y;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						else if (coord.x + 1 < map->row) {				/*�·����*/
							coordtemp.x = coord.x + 1;
							coordtemp.y = coord.y;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						else if (coord.y - 1 >= 0) {					/*�����*/
							coordtemp.x = coord.x;
							coordtemp.y = coord.y - 1;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						else if (coord.y + 1 < map->col) {				/*�ҷ����*/
							coordtemp.x = coord.x;
							coordtemp.y = coord.y + 1;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
					}/*���������ש�����ʾ,�����������*/
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
