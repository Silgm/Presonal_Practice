#ifndef JUDGE_MESSAGE_H_
#define JUDGE_MESSAGE_H_

#include "minemap.h"
#include "maskmap.h"
#include "coordinate.h"
typedef enum _GameState {
	GAMESTATE_RUN		= 0,
	GAMESTATE_WIN		= 1,
	GAMESTATE_FAIL	= 2,
	GAMESTATE_EXIT	= 3
}GameState;

typedef struct _judge_message{
	GameState gameState; 
	Coordinate pos;
	bool refresh;
	int minenums;
}JudgeMessage;


#endif
