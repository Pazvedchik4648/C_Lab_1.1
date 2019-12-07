#include <stdio.h>
#include <string.h>
#define MAX 100

int main()
{
	char name[MAX];
	fgets(name, MAX, stdin);

	int count = 0;

	for (int i = 0; i < strlen(name); i++)
	{
		if (name[i] == 'o')
			count++;
	}

	printf("Quantity of literal o equal %d", count);

}
