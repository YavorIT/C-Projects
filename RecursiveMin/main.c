#include <stdio.h>
#include <stdlib.h>

int findmin (int arr[], int n)
{
    int temp = arr[0], number;

    if (n > 0)
    {
        number = findmin (arr + 1, n - 1);
        if (temp > number)
        {
            temp = number;
        }
    }
    return temp;
}

int main()
{
    int min;
    int a[] = {5, 1, -6, 3, -2};

    min =  findmin (a, sizeof(a));
    printf ("This program prints out the minimum number in a array!\n\n\n");
    printf("The minimum element is: %d\n\n", min);

    return 0;
}
