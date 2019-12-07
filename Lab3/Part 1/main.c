#include <stdio.h>
#include <conio.h>
#define N 13
#define A 0.0
#define B 1.0

int main(void)
{
	int i = 1;
	double x, y, h, s = 0;
	
	h = (B - A) / (N - 1);
	x = A;
	while (x <= B + 1e-6)
	{
		y = exp(-x) + sin(2 * x) - 1.5 * x * x;
		printf("%3d %6.2f %6.2f\n", i, x, y);
		x += h;
		++i;
		s += y * h;
	}
	s -= y * h;
	
	printf("Integral = %f\n", s);
	getch();
	return 0;
}
