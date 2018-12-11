#include "user_main.h"

#define PRACTICE_1

/*Ëã·¨Á·Ï°1: ¿ìËÙÅÅÐò*/
#ifdef PRACTICE_1
typedef int ElmType;

void exchange(ElmType *valA, ElmType *valB)
{
	ElmType tmp;
	tmp = *valA;
	*valA = *valB;
	*valB = tmp;
}

int getMid(int a, int b, int c)
{
	if (b > a && a > c || c > a && a > b)
		return a;
	if (a > b && b > c || c > b && b > a)
		return b;
	if (b > c && c > a || a > c && c > b)
		return c;

}

void quick_sort_getMid(ElmType arr[], int left, int right, ElmType *_output_val, int *_output_index)
{
	int length = right - left + 1;
	if (length > 0)
	{
		int a = arr[left];
		int b = arr[(left + right)/2];
		int c = arr[right];
		int output = getMid(a, b, c);
		int index = 0;
		if (output == a)
			index = arr[0];
		if (output == b)
			index = arr[(left + right) / 2];
		if (output == c)
			index = arr[right];
		*_output_val = output;
		*_output_index = index;
	}
	
}

void quick_sort_core(ElmType arr[], int left, int right)
{
	if (left >= right)
		return;
	int i = left;
	int j = right;
	//int val = arr[left];
	int val;
	int valIndex;
	quick_sort_getMid(arr, left, right, &val, &valIndex);

	while (i < j)
	{
		while (arr[j] >= val && i < j)
			j--;
		while (arr[i] <= val && i < j)
			i++;

		if (i < j)
			exchange(&arr[i], &arr[j]);
	}
	arr[valIndex] = arr[i];
	arr[i] = val;
	quick_sort_core(arr, left, i - 1);
	quick_sort_core(arr, i + 1, right);

}

void quick_sort(ElmType arr[], int length)
{
	quick_sort_core(arr, 0, length - 1);
}

int user_main(int argc, char *argv[])
{
	ElmType arr[8] = { 3,2,5,8,4,7,6,9 };
	quick_sort(arr, 8);
	for (const auto &elm : arr)
	{
		std::cout << elm << "\t";
	}
	return EXIT_SUCCESS;
}

#endif
