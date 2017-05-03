#ifndef JUDGE_MESSAGE_H_
#define JUDGE_MESSAGE_H_

#include "tool.h"
typedef enum _GameState {
	GAMESTATE_RUN		= 0,
	GAMESTATE_WIN		= 1,
	GAMESTATE_FAIL	= 2,
	GAMESTATE_EXIT	= 3
}GameState;

typedef struct _judge_message{
	int maskRow;
	int maskCol;
	GameState gameState;
}JudgeMessage;


#endif
