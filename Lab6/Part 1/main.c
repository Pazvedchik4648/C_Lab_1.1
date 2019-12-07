#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char* jk[1], s[1][60];
	int count = 0;
	printf("Enter the string:\n");

	for (int i = 0; i < 1; i++)
	{
		*(jk + i) = *(s + i);
		fgets(*(jk + i), 60, stdin);
	}

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < strlen(*(jk + i)); j++)
		{
			if (*(*(jk + i) + j) == ' ')
				count++;
		}
		printf("%d", count);
	}
}
