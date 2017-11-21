#include "cl_tool.h"

namespace cl {
	static uint8_t flag = 1;
	double random()
	{
		if (flag) {
				srand((int)time(NULL));
				rand();
				flag = 0;
		}
		return rand() / (RAND_MAX + 1.0);
	}

	int random_int(int n)
	{
		if (flag) {
			srand((int)time(NULL));
			rand();
			flag = 0;
		}
		return int(double(rand()) * ( double(n) / double(RAND_MAX))) ;
	}
	int random_int(int start, int end)
	{
		if (flag) {
			srand((int)time(NULL));
			rand();
			flag = 0;
		}
		return start + int(double(rand()) * (double(end - start) / double(RAND_MAX)));
	}
}
