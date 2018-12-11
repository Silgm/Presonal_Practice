#include "user_main.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "tool.h"

#define PRACTIC_1
/*Practic1:Quick Sort*/
#ifdef PRACTIC_1

/*
 *笔记:	使用三数取中的快速排序比使用普通模式的快速排序
 *		在待排数组大于1000000(一百万)的时候才开始有明显区别
 *		且待排数组越大, 差别越大;
 *		在待排数组小于1000000的时候差别不明显
*/

typedef int ElmType;

void exchange(int *val1, int *val2)
{
	int tmp = *val1;
	*val1 = *val2;
	*val2 = tmp;
}

/*三数取中快速排序*/
static void quick_sort_core_pre(int arr[], int left, int right)
{
	int tmp[3];
	int mid = (left + right) / 2;
	tmp[0] = arr[left];
	tmp[1] = arr[mid];
	tmp[2] = arr[right];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			if (tmp[j] < tmp[i])
				exchange(&tmp[i], &tmp[j]);
		}
	}

	arr[left] = tmp[0];
	arr[mid] = tmp[1];
	arr[right] = tmp[2];

	exchange(&arr[mid], &arr[left + 1]);
}

void quick_sort_core_good(int arr[], int left, int right)
{
	if (left >= right)
		return;
	quick_sort_core_pre(arr, left, right);
	int i = left + 1;
	int j = right;
	int val = arr[left + 1];
	while (i < j)
	{
		for (; i < j && arr[j] >= val; j--);
		for (; i < j && arr[i] <= val; i++);
		if (i < j)
			exchange(&arr[i], &arr[j]);
	}
	arr[left + 1] = arr[i];
	arr[i] = val;
	quick_sort_core_good(arr, left , i - 1);
	quick_sort_core_good(arr, i + 1, right);
}

void quick_sort_good(int arr[], int length)
{
	quick_sort_core_good(arr, 0, length - 1);
}

//普通快速排序
void quick_sort_core(int arr[], int left, int right)
{
	if (left >= right)
		return;

	int i = left;
	int j = right;
	int val = arr[left];
	while (i < j)
	{
		for (; i < j && arr[j] >= val; j--);
		for (; i < j && arr[i] <= val; i++);
		if (i < j)
			exchange(&arr[i], &arr[j]);
	}
	arr[left] = arr[i];
	arr[i] = val;
	quick_sort_core(arr, left, i - 1);
	quick_sort_core(arr, i + 1, right);
}

void quick_sort(int arr[], int length)
{
	quick_sort_core(arr, 0, length - 1);
}


#define LEN	20000000

int user_main(int argc, char * argv[])
{
	DWORD start, end;

	int *arr1 = (int *)malloc(sizeof(int)*LEN);
	int *arr2 = (int *)malloc(sizeof(int)*LEN);

	rand_init();
	rand_arr_int(arr1, LEN);
	memcpy_s(arr2, sizeof(arr2), arr1, sizeof(arr1));

	start = GetTickCount();//or time(&start);  
	quick_sort_good(arr1, LEN);
	end = GetTickCount();

	
	printf("Good Time:%d ms\n", end - start);

	//print_arr_int(arr, LEN);

	rand_init();
	rand_arr_int(arr2, LEN);
	start = GetTickCount();//or time(&start);  
	quick_sort(arr2, LEN);
	end = GetTickCount();
	printf("Bad Time:%d ms\n", end - start);

	free(arr1);
	free(arr2);

	return EXIT_SUCCESS;
}
#endif
