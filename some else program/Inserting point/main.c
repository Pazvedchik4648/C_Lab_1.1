#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

struct school
{
	float x, y;
	float a, b;
};

struct school calculate_lines(float x1, float y1, float x2, float y2);

int main()
{
	float intersection_X, intersection_Y;
	float x1, y1, x2, y2;

	printf("Program to find the intersecting point of two lines:\n");
	printf("Enter Line1 - X1: ");

	scanf("%fl", &x1);

	printf("Enter Line1 - Y1: ");
	scanf("%fl", &y1);

	printf("Enter Line1 - X2: ");
	scanf("%fl", &x2);

	printf("Enter Line1 - Y2: ");
	scanf("%fl", &y2);

	struct school result = calculate_lines(x1, y1, x2, y2);

	printf("Equation of line1: Y = %.2fX %c %.2f\n", result.x, (result.a < 0) ? ' ' : '+', result.a);
	printf("Equation of line2: Y = %.2fX %c %.2f\n", result.y, (result.b < 0) ? ' ' : '+', result.b);

	if ((result.x - result.y) == 0)
		printf("The lines is parallel\n");
	else
	{
		intersection_X = (result.b - result.a) / (result.x - result.y);
		intersection_Y = result.x * intersection_X + result.a;

		printf("Intersecting Point: = %.2f, %.2f\n", intersection_X, intersection_Y);
	}
}
struct school calculate_lines(float x1, float y1, float x2, float y2)
{
	float intersection_X, intersection_Y;
	float m1, c1, m2, c2;
	float dx, dy;

	dx = x2 - x1;
	dy = y2 - y1;

	m1 = dy / dx;

	c1 = y1 - m1 * x1;

	printf("Enter Line2 - X1: ");
	scanf("%f", &x1);

	printf("Enter Line2 - Y1: ");
	scanf("%f", &y1);

	printf("Enter Line2 - X2: ");
	scanf("%f", &x2);

	printf("Enter Line2 - Y2: ");
	scanf("%f", &y2);

	dx = x2 - x1;
	dy = y2 - y1;

	m2 = dy / dx;

	c2 = y1 - m2 * x1;

	struct school res;

	res.x = m1;
	res.y = m2;
	res.a = c1;
	res.a = c2;

	return res;
}