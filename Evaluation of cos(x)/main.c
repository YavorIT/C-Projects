#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double cosx(double x);

int main()
{
    int xgr;
    double xrad;

    printf ("Input x:");
    scanf("%d", &xgr);

    xrad = xgr / 180. * M_PI;

    printf("cos(%d) = %lf ", xgr, cosx(xrad) );
    return 0;
}


double cosx(double x){


    int i;
    double sum = 0;
    double ch = 1;
    int n = 1;

    for (i = 1; i <= 100; i++){

        ch = ch * (x * x * (-1)) / (n * (n+1));
        n += 2;
        sum += ch;
        }
        return sum + 1;
}
