#include "..\head\judge.h"
/************************************************************************/
/* 
�����й���Ϸ�߼����ж϶����ɲ���ģ������ж�
����ģ��������Կ���ģ������Ŀ�����Ϣcmsg
��cmsg���н���, ��ȡ��ҵ�ǰ�İ�����Ϣ, �͵�ǰ�Ĺ��λ��
�����ݵ�ǰcmsg, ����Ϸ�ĵ�ͼ, ״̬���и���.
����JudgeMessage���ݳ���, ������ģ�����
*/
/************************************************************************/


JudgeMessage Judge(const MineMap * map, MaskMap * maskmap, const ContolMessage cmsg)
{
	JudgeMessage jmsg;
	static current_flag_num = 0;
	jmsg.refresh = false;
	jmsg.gameState = GAMESTATE_RUN;
	jmsg.pos = cmsg.pos;
	/*������µ��Ǽ���X��, �Ҵ�ʱ��maskmapλ���ǲ��ɼ���, ��ִ�з�������, �����ʲôҲ����*/
	if (cmsg.key == KEY_X && maskmap->map[cmsg.pos.x][cmsg.pos.y] == MASKSTATE_INVISIBLE) {
		jmsg.refresh = true;

		/*���ѡ�е��Ƿ������ַ���*/
		if (map->map[cmsg.pos.x][cmsg.pos.y] > BLOCK_0 && map->map[cmsg.pos.x][cmsg.pos.y] <= BLOCK_8) {
			jmsg.gameState = GAMESTATE_RUN;
			maskmap->map[cmsg.pos.x][cmsg.pos.y] = MASKSTATE_VISUAL;
			return jmsg;
		}/*���ѡ�е��ǵ���ש��*/
		else if (map->map[cmsg.pos.x][cmsg.pos.y] == BLOCK_MINE) {
			jmsg.gameState = GAMESTATE_FAIL;
			return jmsg;
		}/*���ѡ�е�������0����*/
		else if (map->map[cmsg.pos.x][cmsg.pos.y] == BLOCK_0) {
			jmsg.gameState = GAMESTATE_RUN;
			/*������ȱ���*/

			CoordinateQueue *coordQueue;
			CoordinateQueue_new(&coordQueue);
			CoordinateQueue_en(coordQueue, cmsg.pos);

			while (!CoordinateQueue_isEmpty(coordQueue)){
				Coordinate coord = CoordinateQueue_de(coordQueue);

				if (maskmap->map[coord.x][coord.y] == MASKSTATE_INVISIBLE) {
					/*������ӵ���BLOCK_0����Ļ�,���ڱβ�Ϊ���ɼ�,��mask����ʾ, ���ҽ��������ҵ�ש��Ҳ���*/
					maskmap->map[coord.x][coord.y] = MASKSTATE_VISUAL;
					if (map->map[coord.x][coord.y] == BLOCK_0 ) {
						Coordinate coordtemp;
						if (coord.x - 1 >= 0) {							/*�Ϸ����*/
							coordtemp.x = coord.x - 1;
							coordtemp.y = coord.y;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						if (coord.x + 1 < map->row) {				/*�·����*/
							coordtemp.x = coord.x + 1;
							coordtemp.y = coord.y;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						if (coord.y - 1 >= 0) {					/*�����*/
							coordtemp.x = coord.x;
							coordtemp.y = coord.y - 1;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
						if (coord.y + 1 < map->col) {				/*�ҷ����*/
							coordtemp.x = coord.x;
							coordtemp.y = coord.y + 1;
							CoordinateQueue_en(coordQueue, coordtemp);
						}
					}/*�������������ש�����ʾ,�����������*/
					else if (map->map[coord.x][coord.y] >= BLOCK_1 && map->map[coord.x][coord.y] <= BLOCK_8) {
						maskmap->map[coord.x][coord.y] = MASKSTATE_VISUAL;
					}
				}
			}
			CoordinateQueue_free(&coordQueue);
		}
	}/*������µ���z��, ��˼������С����, */
	else if (cmsg.key == KEY_Z) {

		jmsg.refresh = true;

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
