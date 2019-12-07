#include <stdio.h>
#include <stdlib.h>
#define N 256

int main()
{
	char str[N] = "", * ptr;
	int sum = 0, n = 0;

	while ((str[n] = getchar()) != '=') ++n;
	++n;
	str[n] = '\0';

	for (int i = 0; i < n; ++i)
	{
		if (i == 0) sum = atoi(str), ++i;
		if (str[i] == '+' || str[i] == '-')
		{
			ptr = &str[i];
			sum += atoi(ptr);
		}
	}

	printf("%d", sum);

	return 0;
}