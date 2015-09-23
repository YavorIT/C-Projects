#include <stdio.h>
#include <stdlib.h>

int main()
{
    char Array[50], ex;
    char Mirrored[strlen(Array)];
    int i, j;
    jump:;
    printf ("Enter the string you want to mirror! (NO MORE THAN 50 SYMBOLS)\n");
    fgets(Array, 50, stdin);
    fflush(stdin);
    printf("Before the work: %s \n", Array);
    for (i=0, j = (strlen(Array)-1); i < strlen(Array); i++, j--) {
        Mirrored [i] = Array[j];
    }
    Mirrored [strlen (Array)] = '\0';
    printf("After the work: %s \n", Mirrored);
    fflush(stdin);
    printf("Do you want to exit? y/n");
        scanf("%c", &ex);
    fflush(stdin);
    if (ex == 'y'){
        exit(1);
    }else{
    goto jump;
    }
    return 0;
}
