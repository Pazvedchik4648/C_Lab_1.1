#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int hightmax;
	scanf("%d", &hightmax);
	char asterisk = '*';

	for (int i = 0; i < hightmax; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf("%c", asterisk);
		printf("\n");
	}

	return 0;
}