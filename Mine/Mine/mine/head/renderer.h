#ifndef RENDERER_H_
#define RENDERER_H_


#include "interfaceMessage.h"
typedef enum FONT_COLOR
{
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_BGREEN = 3,
	COLOR_RED = 4,
	COLOR_PURPLE = 5,
	COLOR_YELLOW = 6,
	COLOR_WHITE = 7,
	COLOR_GRAY = 8,
	COLOR_LBLUE = 9,
	COLOR_LGREEN = 10,
	COLOR_LBGREEN = 11,
	COLOR_LRED = 12,
	COLOR_LPURPLE = 13,
	COLOR_LYELLOW = 14,
	COLOR_BWHITE = 15
}Color;

void Render(const InterfaceData * interfacemap, InterfaceMessage imsg);

#endif // !RENDERER_H_

