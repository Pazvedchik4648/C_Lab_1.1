#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

int binary_search(int* array, int search);

int main(void)
{
	int search = 13;
	scanf("%d", &search);

	int array[MAX] = {1, 3, 5, 7, 9, 12, 13, 14, 16, 18};
	int result = array[binary_search(array, search)];

	printf("Number %d", result);
}

int binary_search(int* array, int search)
{
	int low = 0;
	int hight = MAX;

	
	while (low <= hight)
	{
		int mid = (low + hight) / 2;

		if (search = array[mid])
			return mid;
		if (search > array[mid])
			low = mid + 1;
		if (search < array[mid])
			hight = mid - 1;
	}
}