#include <stdio.h>

unsigned long int fact (int number)
{
    unsigned long int temp = number;
    if (number > 1)
    {
        temp *= fact (number - 1);
        return temp;
    }else
    {
        return 1;
    }
}

int main()
{
    unsigned long int answer;
    int number;
       printf ("Enter the number (not higher than 33) which factorial you want to find: ");
       scanf ("%d", &number);

       answer = fact (number);

        printf ("The answer is: %lu", answer);
    return 0;
}

