#ifndef CONTROLLER_MESSAGE_H_
#define CONTROLLER_MESSAGE_H_

#include "tool.h"
#include "coordinate.h"

typedef enum _key {
	KEY_ESC = 27,
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	KEY_Z = 'z',
	KEY_X = 'x',
	KEY_OTHER = '\0'
}Key;


typedef struct _controller_message {
	Key key;	//±£´æµÄ°´¼ü
	Coordinate pos;
}ContolMessage;





#endif
