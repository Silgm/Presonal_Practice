#ifndef _USER_MAIN_H_
#define _USER_MAIN_H_

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdio>

#ifdef _DEBUG //жидиnew  
#define new  new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

#include <cstdlib>
#include "CMainApp.h"
int user_main(int argc, char *argv[]);


#endif

