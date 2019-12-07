#include <stdio.h>
#include <math.h>

unsigned long long factorial(unsigned long long number);

int main()
{
	double eps, x, step;

	printf("Enter x:\n");
	scanf("%lf", &x);
	printf("Enter accuracy:\n");
	scanf("%lf", &eps);

	double y = (1 + 2 * x * x) * exp(x * x);
	double partial_sum = 1;
	double sum = 0.0;
	unsigned long long k = 0;

	while (partial_sum > eps)
	{
		partial_sum = (2 * k + 1) * pow(x, 2 * k) / factorial(k);
		sum += partial_sum;
		k++;
	}

	printf("For x = %f:\n", x);
	printf("y(x) = %f, s(x) = %f\n", y, sum);
	printf("Error: %f", fabs(y - sum));
}

unsigned long long factorial(unsigned long long number)
{
	unsigned long long result = 1;

	for (int i = number; i > 0; i--)
		result *= i;

	return result;
}
