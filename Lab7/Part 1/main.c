#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double input_step(void);
double InFunction(double x);
double CalcIntegral(double a, double b);
void print_integral(double integral);

int main(void)
{
	print_integral(CalcIntegral(0, 3.14159265));
	return 0;
}

double InFunction(double x)
{
	return pow(sin(x), 3) - 3 * x;
}

double input_step(void)
{
	double s;

	printf("Enter a step:\n");
	scanf("%lf", &s);
	return s;
}
double CalcIntegral(double a, double b)
{
	double result, h, n;
	result = 0;

	h = input_step();
	n = b - a / h + 1;

	for (int i = 0; i < n; i++)
	{
		result += InFunction(a + h * (i + 0.5));
	}
	result *= h;
	return result;
}
void print_integral(double integral)
{
	printf("The value of the integral is: %f \n", fabs(integral));
}