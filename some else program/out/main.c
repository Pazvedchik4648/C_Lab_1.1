//Написати програму, що не завершує роботу, поки користувач не введе символ 'q'
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char option = 'a';

	while (option != 'q')
	{
		scanf("%c", &option);
	}

	return 0;
}