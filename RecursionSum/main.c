#include <stdio.h>
#include <stdlib.h>

unsigned long int sum (int number)
{
    if (number == 0)
        return 0;

        return number + sum(number - 1);
}

int main()
{

    int number;
    printf ("This program uses recursion to calculate the sum of the numbers 0 - n!\n");
    printf("Enter a number \"n\": ");
    scanf ("%d", &number);
    fflush(stdin);

    printf ("%lu", sum(number));

    return 0;
}
