#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sinx(double x);
double cosx(double x);

int main()
{
    int choice, xgr;
    char exit;
    double xrad;
    start:;
    //          MENU
    printf("Which operation do you want? \n \n");

    printf("sin(x)  - 1\n");
    printf("cos(x)  - 2\n");
    printf("tg(x)   - 3\n");
    printf("cotg(x) - 4\n");

    scanf("%d", &choice);
        fflush(stdin);


    if (choice == 1){
            printf ("Input x in degrees:  ");
            scanf("%d", &xgr);
            fflush(stdin);
            xrad = xgr / 180. *M_PI;
        printf("sin(%d) = %.2f", xgr, sinx(xrad));
    }

    if (choice == 2){
             printf ("Input x in degrees:  ");
            scanf("%d", &xgr);
            fflush(stdin);
            xrad = xgr / 180. *M_PI;
        printf("cos(%d) = %.2f", xgr, cos(xrad));
    }

    if (choice == 3){
             printf ("Input x in degrees:  ");
            scanf("%d", &xgr);
            fflush(stdin);
            xrad = xgr / 180. *M_PI;
        printf("tg(%d) = %.2f", xgr, (sinx(xrad)/ cosx(xrad)));
    }

    if (choice == 4){
             printf ("Input x in degrees:  ");
            scanf("%d", &xgr);
            fflush(stdin);
            xrad = xgr / 180. *M_PI;
        printf("cotg(%d) = %.2f", xgr, (cosx(xrad) / sinx(xrad)));
    }
        printf("\nIf you want to continue hit \"A\" if not hit \"Q\" \n");
            scanf("%c", &exit);
        if (exit == 'a' || exit == 'A'){
            goto start;
        }

    return 0;
}



double sinx (double x){

  double sum = x;
  double ch = x;
  int i, n = 2;

    for (i = 1; i <=20; i++){

        ch = ch * (x * x * (-1)) / (n * (n+1));
         n += 2;
         sum += ch;
    }
  return sum;

}


double cosx(double x){


    int i;
    double sum = 1;
    double ch = 1;
    int n = 1;

    for (i = 1; i <= 20; i++){

        ch = ch * (x * x * (-1)) / (n * (n+1));
        n += 2;
        sum += ch;
        }
        return sum;
}
