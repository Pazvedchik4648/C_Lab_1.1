#include <stdio.h>
#define SIZE 10

void main()
{
	double unsorted[SIZE] = { 1.0, 3.0, 2.0, 4.0, 5.0, 6.0, 8.0, 7.0, 9.0, 0.0 };
	double* p[SIZE];
	double* tmp;
	char flag = 1;
	unsigned i;

	printf("unsorted array\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%.2f ", unsorted[i]);
	}
	printf("\n");

	for (i = 0; i < SIZE; i++)
	{
		p[i] = &unsorted[i];
	}

	do
	{
		flag = 0;
		for (i = 1; i < SIZE; i++)
		{
			if (*p[i] < *p[i - 1])
			{
				//обмениваем местами АДРЕСА
				tmp = p[i];
				p[i] = p[i - 1];
				p[i - 1] = tmp;
				flag = 1;
			}
		}
	} while (flag);

	printf("sorted array of pointers\n");
	for (i = 0; i < SIZE; i++) {
		printf("%.2f ", *p[i]);
	}
	printf("\n");

	printf("make sure that unsorted array wasn't modified\n");
	for (i = 0; i < SIZE; i++) {
		printf("%.2f ", unsorted[i]);
	}
}