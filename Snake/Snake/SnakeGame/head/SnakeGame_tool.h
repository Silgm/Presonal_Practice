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
}


#endif
