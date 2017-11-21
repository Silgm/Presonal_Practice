#ifndef _CL_TOOL_H_
#define _CL_TOOL_H_

#include <thread>
#include <mutex>
#include <atomic> 

#include <iostream>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <numeric>

#include <array>
#include <vector>
#include <deque>
#include <string>
#include <corecrt_wstring.h>

#include <list>
#include <forward_list>

#include <map>
#include <set>

#include <functional>

#include <iterator>

#include <initializer_list>


#include <stack>
#include <queue>

#include <typeinfo>
#include <exception>
#include <stdexcept>
#include <initializer_list>


#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>

#include <conio.h>
#include <windows.h>

namespace cl {
#define THIS_THREAD_DELAY_S(s)		(std::this_thread::sleep_for(std::chrono::seconds(s)))
#define THIS_THREAD_DELAY_MS(ms)	(std::this_thread::sleep_for(std::chrono::milliseconds(ms)))
#define THIS_THREAD_DELAY_US(us)	(std::this_thread::sleep_for(std::chrono::microseconds(us)))
	double random();	//返回一个0~1的随机实数
	int random_int(int n);	//返回一个0~n-1的随机整数
	int random_int(int start , int end);	//返回一个start~end-1的随机整数
}


#endif
