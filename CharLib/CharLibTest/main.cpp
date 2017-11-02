#include "user_main.h"

int main(int argc, char *argv[])
{
	int returnVal = user_main(argc, argv);
	int MemleaksNums = _CrtDumpMemoryLeaks();
#ifdef _DEBUG
	std::printf("\nLeaks:%d\n", MemleaksNums);
#endif
	return returnVal;
}

