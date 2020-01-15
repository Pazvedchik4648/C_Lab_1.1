#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int space, hight, k = 0;
	printf("Enter hight of pyramida: ");
	scanf("%d", &hight);

	for (int i = 1; i <= hight; ++i)
	{
		for (space = 0; space < hight - i; space++)
		{
			printf("  ");
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}