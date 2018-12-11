#ifndef _USER_MAIN_H_
#define _USER_MAIN_H_


#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC 
#endif

#include <cstdlib>

#ifdef _DEBUG
#include <crtdbg.h>
#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

/*
 *	Head File
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <sstream>
#include <fstream>

#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <memory>


#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>

int user_main(int argc, char *argv[]);

#endif
