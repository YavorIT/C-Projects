#include <stdio.h>
#include <stdlib.h>

int main()
{
    jump:;
    char mass [10], k, ex;
    int i, j;
    time_t t;
    printf("Enter the  symbols which will be shuffled! (NO MORE THAN 9)\n");
        fgets (mass, 10, stdin);
    printf("You entered: %s \n", mass);
    srand((unsigned) time(&t));
        for (i = 0, j = 0; i<(strlen(mass) - 1); i++, j = rand()%(strlen(mass) - 1)){
            if (i == 0){
                continue;
            }
            else
            {
                k = mass[j];
                mass[j] = mass[i];
                mass [i] = k;
            }
        }
    printf ("The shuffled string is: %s \n", mass);
    fflush(stdin);
    printf ("Do you want to exit? - y/n \n");
        scanf("%c", &ex);
    fflush(stdin);
    if(ex == 'y'){
    exit(1);
    }else if (ex == 'n'){
        goto jump;
    }
    return 0;
}
