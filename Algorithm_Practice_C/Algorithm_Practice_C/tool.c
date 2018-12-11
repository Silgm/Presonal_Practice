#include "tool.h"

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void rand_init()
{
	srand((int)(time(NULL)));
}

void rand_arr_int(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		arr[i] = rand();
	}
}

void print_arr_int(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
	{
		printf("%d, ", arr[i]);
	}
	puts("");
}
