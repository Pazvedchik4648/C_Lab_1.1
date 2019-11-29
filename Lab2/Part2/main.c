#include <stdio.h>
#include <conio.h>
#include <math.h>

int main(void)
{
    printf("Please input z:\n");
    double  z, y, x;
    scanf("%lf", &z);

    if(z<0)
    {
     x = z;
     y = (2.0/3.0*(pow(sin(x), 2))) - (3.0/4.0*(pow(cos(x), 2)));
     printf("d = %f\n", y);
    }
    else
    {
     x = sin(z);
     y = 2.0/3*(pow(sin(x), 2)) - 3.0/4*(pow(cos(x), 2));
     printf("d = %f\n", y);
    }

    getch();
    return 0;
}