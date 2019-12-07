#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
	int arr[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
		printf("arr[%d] = %d\n", i, arr[i]);
		arr[++i] = -rand() % 100;
		printf("arr[%d] = %d\n", i, arr[i]);
	}

	printf("\n\n");

	int count = 0;
	int num = N;

	for (int i = 0; i < num; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (arr[j] != 0 && arr[i] / (double)arr[j] == -1.0)
			{
				printf("First equal number (index: %d): %d\n", i, arr[i]);
				printf("Second equal number (index: %d): %d\n", j, arr[j]);
				count++;
				num--;
				for (int k = j; k < num; k++)
					arr[k] = arr[k + 1];
				printf("\n");
				break;
			}
		}
	}

	printf("Quantity of the same number with different signs is %d\n", count);
	return 0;
