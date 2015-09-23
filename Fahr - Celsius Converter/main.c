#include <stdio.h>
#include <math.h>

 int main ()
{
	long fahr, celsius;
	int num;
	printf("fahr to celsuis - 1:  \nCelsius to fahr - 2: \n");
	scanf("%d", &num);
	if (num==1)
	{
		printf("fahr = ");
			scanf("%ld", &fahr);
		printf("Celsius = %ld\n", 5 * (fahr - 32) /9);
	}
	if (num==2)
	{
		printf("Celsius = ");
			scanf("%ld", &celsius);
		printf("Fahr = %ld\n", (9 * celsius + 160) /5);
	}
	system ("pause");
	return 0;
}
