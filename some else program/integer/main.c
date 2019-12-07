//Ввести з клавіатури ціле число.Вивести на екран його третю цифру, якщо така є

#include <stdio.h>

int main()
{
	unsigned int n;

	scanf("%u", &n);

	if (n <= 99)
		return -1;

	while (n > 999)
		n /= 10;

	printf("%u", n % 10);
	return 0;
}