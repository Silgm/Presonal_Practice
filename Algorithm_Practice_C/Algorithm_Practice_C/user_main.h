#ifndef _USER_MAIN_H_
#define _USER_MAIN_H_

#include <stdlib.h>


#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC 
#endif


#ifdef _DEBUG
#include <crtdbg.h>
#endif

int user_main(int argc, char *argv[]);


#endif
