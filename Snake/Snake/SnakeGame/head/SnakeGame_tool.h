#ifndef _SNAKEGAME_TOOL_H_
#define _SNAKEGAME_TOOL_H_

//C++ std library
#include <iostream>
#include <string>
#include <vector>
#include <thread>

//C	std library
#include <ctime>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <climits>
#include <cstddef>

//Windows api
#include <windows.h>
#include <conio.h>

//Userful function

namespace tool {
	template<typename TYPE>
	void tool_PrintVec(std::vector<TYPE> vec) {
		for (auto data : vec) {
			std::cout << data << '\t' << std::endl;
		}
	}

	template<typename TYPE>
	TYPE tool_random(TYPE start, TYPE end) {
		static bool flag = true;
		if (flag) {
			srand(int(time(NULL)));
			rand();
			flag = false;
		}
		return (TYPE)(((rand() / (RAND_MAX + 1.0))*(end - start) + 0.5) + start);
	}

}


#endif
