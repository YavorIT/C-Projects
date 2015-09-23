#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

int Fchoice();

int main()
{
    char ch[1024];
    char *Letters = NULL, *tempc = NULL, charac;
    int *Counting = NULL, i, j, *tempi = NULL, count = 0, MAX, flag = 0, choice;

    choice = Fchoice();

    printf ("Enter the one lined string: ");
    fgets(ch, 1024, stdin);
    ch [strlen(ch) - 1] = '\0';

    fflush(stdin);
/////////////////////////////////////////////////////////////////////////////////
    if((Letters = (char*) calloc (1, sizeof(char))) == NULL)
        {
        printf ("Error \n");
        exit(1);
        }

    if ((Counting = (int*) calloc (1, sizeof (int))) == NULL)           // Memory allocation
    {
        printf ("Error \n");
        exit(2);
    }
/////////////////////////////////////////////////////////////////////////////////
            if (choice == 1){
                for(i = 0; i < strlen(ch); i++)
                {
                    if (isalpha(ch[i]))
                    {
                        Letters [0] = ch[i];                    // User's choice
                        if(i != 0){
                            Counting [0] = - 1;
                            }
                        break;
                        }
                }

            }else if (choice == 2)
                Letters [0] = ch [0];
////////////////////////////////////////////////////////////////////////////////

    for(i = 0, count = 1; i < (strlen(ch)); i++)
    {
        if (choice == 1){
            if(!isalpha(ch[i]))
            {
                continue;
            }
        }

////////////////////////////////////////////////////////////////////////////////////////////////
               tempc = (char*) realloc (Letters, count*sizeof(char));
        if (tempc!=NULL){
        Letters = tempc;
        }else {
            printf("Error \n");
            exit(3);
        }

    tempi = (int*) realloc (Counting, (strlen(Letters) + count)*sizeof(int));   // Memory allocation
    if (tempi != NULL){
        Counting = tempi;
    }else {
    printf ("Error \n");
    exit(4);
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
        for (j = 0; j < i; j++)
         {
          if (ch[i] == Letters [j])
            {
                Counting[j] += 1;
                 break;
            }else if(*(Letters + (j + 1)) == '\0')               //  Searching for new characters and counting them
             {
                *(Letters  + (j + 1)) = ch [i];
               Counting[j] += 1;
               break;
             }

         }
         count++;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////
    for(i = 0; i<strlen(Letters); i++)
    {
        if (i == strlen(Letters) - 1)
            *(Counting + i) += 1;
                                                           // Printing everything on the screen
        if (i % 10 == 0)
            printf ("\n\n");

        printf("|%c : %d|   ", Letters[i], *(Counting + i));
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////
        MAX = 0;
        charac = Letters[0];
        for (i = 0; i < (strlen(Letters)); i++)
        {
            if (Counting[i] > MAX)
            {
                MAX = Counting [i];
                charac = Letters[i];                          // Searching for the most common character
                flag = 0;
                continue;
            }
             if ((Counting [i] == MAX) && (flag == 0)){
                flag = 1;
            }
        }
//////////////////////////////////////////////////////////////////////////////////////////////////////
        if (flag == 0){
        printf ("\nMost common character is: |%c| - |%d| times\n", charac, MAX);
        }else                                                                           // Printing the character out
        {
            printf (" \nThere are more than one characters met max times.");
        }
//////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n");
    system("pause");
    free(Counting);
    free(Letters);
    free(tempc);
    free(tempi);
    return 0;
}


// Function recognizing the user's choice
int Fchoice()
{
    int a;

    printf ("To count only the letters hit 1.");
    printf ("\nTo count every single character hit 2.\n");
    printf("\n Your choice is: ");
    scanf("%d", &a);
    fflush(stdin);

    return a;
}
