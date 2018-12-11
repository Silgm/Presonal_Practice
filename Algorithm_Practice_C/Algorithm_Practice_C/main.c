#include "user_main.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	int retVal = user_main(argc, argv);

#ifdef _DEBUG
	int leak = _CrtDumpMemoryLeaks();
	printf("\nLeaks:%d\n", leak);
#endif
	return retVal;
}