#include <stdio.h>
#include <stdlib.h>

void counter ();
int main()
{
   int choice;
   printf ("Enter the number to stop: ");
   scanf ("%d", &choice);

   counter (choice, 0, 1);
    return 0;
}

void counter (int number, int prev, int curr)
{
    if (curr < number)
    {
        printf ("%d ", curr);
        counter (number, curr, curr+prev);
    }
}
