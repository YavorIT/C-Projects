#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    float *forSorting = NULL, temp;
    int i, m, count;
    printf ("Please if the number is with floating point write it with \".\" \n \n \n");
    printf ("How many number you're going to sort? \n");
    scanf ("%d", &count);
    fflush(stdin);
    forSorting = (float*) calloc (count, sizeof(float));
    for (m = 0; m<count; m++){
    printf ("Enter the %d number\n", m + 1);
    scanf("%f", forSorting + m);
    fflush(stdin);
        for (i = 0; i < m; i++)
        {
            if (( forSorting [m] < forSorting [i]) && (m != 0))
            {
                temp = forSorting [i];
                forSorting [i] = forSorting [m];
                forSorting [m] = temp;
            }
        }
    }
    for (i = 0; i<count; i++)
    printf ("%.2f ", forSorting[i]);
    system("pause");
    free(forSorting);
    return 0;
}
