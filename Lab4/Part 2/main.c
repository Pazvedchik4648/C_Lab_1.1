#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define N 4

int A[N][N];

int main()
{
	FILE* f1 = fopen("F1.txt", "w");
	if (f1)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				A[i][j] = rand() % 10;
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				fscanf(f1, "%d ", &A[i][j]);

			}
			printf("\n");
		}
		fclose(f1);


		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf(" %d\n", A[i][j]);
			}
		}

		FILE* f2 = fopen("F2.txt", "w");
		sorting(A);

		if (f2)
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
					fprintf(f2, "%d ", A[i][j]);

				fprintf(f2, "\n");
			}
		}
		else
			printf("Error\n");

	}

}
int sorting()
{
	int min;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			min = A[i][j];
			if (A[i][j] < min)
				min = A[i][j];
			if (A[i][j] != 0)
			{
				int tmp = min;
				min = A[i][j];
				A[i][j] = tmp;
			}
		}
	}

	return 1;
}
