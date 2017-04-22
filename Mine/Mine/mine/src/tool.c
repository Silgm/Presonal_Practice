#include "../head/tool.h"

double random()
{
	static uint8_t flag = 1;
	if (flag) {
		srand((int)time(NULL));
		rand();
		flag = 0;
	}
	return rand() / (RAND_MAX + 1.0);
}


