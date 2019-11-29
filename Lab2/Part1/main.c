#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
    printf("Please input x, y, z\n");
    double x, y, z, d;
    scanf("%lf %lf %lf", &x, &y, &z);

    if((asin(z)!=0) && ((10*(pow(x, 1.0/3/0)) + pow(x, x+2)) >= 0))
    {
     d = sqrt(10*((pow(x, 1.0/3.0)) + pow(x, y+2)))*(pow(asin(z), 2) - fabs(x-y));
     printf("d = %f\n", d);
    }
    else
        printf("Error\n");

    getch();
    return 0;
}