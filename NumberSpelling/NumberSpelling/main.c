#include <stdio.h>

int main (){

	int number, flag = 0;
	char Name [50];

	printf ("Enter a number between 1 and 999:");
		scanf ("%d", &number);
	fflush(stdin);

	if ( ((number % 1000) >= 100) && ((number % 1000) < 200))
		printf ("One hundred ");
	if ( ((number % 1000) >= 200) && ((number % 1000) < 300))
		printf ("Two hundred ");
	if ( ((number % 1000) >= 300) && ((number % 1000) < 400))
		printf ("Three hundred ");
	if ( ((number % 1000) >= 400) && ((number % 1000) < 500))
		printf ("Four hundred ");
	if ( ((number % 1000) >= 500) && ((number % 1000) < 600))
		printf ("Five hundred ");
	if ( ((number % 1000) >= 600) && ((number % 1000) < 700))
		printf ("Six hundred ");
	if ( ((number % 1000) >= 700) && ((number % 1000) < 800))
		printf ("Seven hundred ");
	if ( ((number % 1000) >= 800) && ((number % 1000) < 900))
		printf ("Eight hundred ");
	if ( ((number % 1000) >= 900) && ((number % 1000) < 1000))
		printf ("Nine hundred ");

	if (((number % 1000) > 100) && ((number % 1000) < 1000))
		printf ("and ");
	
	if (((number % 100) >= 20) && ((number % 100) < 30))
		printf ("Twenty ");
	if ( ((number % 100) >= 30) && ((number % 100) < 40))
		printf ("Thirty ");
	if ( ((number % 100) >= 40) && ((number % 100) < 50))
		printf ("Forty ");
	if ( ((number % 100) >= 50) && ((number % 100) < 60))
		printf ("Fifty ");
	if ( ((number % 100) >= 60) && ((number % 100) < 70))
		printf ("Sixty ");
	if ( ((number % 100) >= 70) && ((number % 100) < 80))
		printf ("Seventy ");
	if ( ((number % 100) >= 80) && ((number % 100) < 90))
		printf ("Eighty ");
	if ( ((number % 100) >= 90) && ((number % 100) < 100))
		printf ("Ninety ");

	if (((number % 100) > 20) && ((number % 100) < 100))
		printf ("- ");
	
	if ((number % 100) == 11){
		printf ("Eleven\n");
		flag = 1;
	}
	if ((number % 100) == 12){
		printf ("Twelve\n");
		flag = 1;
	}
	if ((number % 100) == 13){
		printf ("Thirteen\n");
		flag = 1;
	}
	if ((number % 100) == 14){
		printf ("Fourteen\n");
		flag = 1;
	}
	if ((number % 100) == 15){
		printf ("Fifteen\n");
		flag = 1;
	}
	if ((number % 100) == 16){
		printf ("Sixteen\n");
		flag = 1;
	}
	if ((number % 100) == 17){
		printf ("Seventeen\n");
		flag = 1;
	}
	if ((number % 100) == 18){
		printf ("Eighteen\n");
		flag = 1;
	}
	if ((number % 100) == 19){
		printf ("Nineteen\n");
		flag = 1;
	}
if (flag != 1){
	if (((number % 10) >= 1) && ((number % 10) < 2))
		printf ("One \n");
	if (((number % 10) >= 2) && ((number % 10) < 3))
		printf ("Two \n");
	if (((number % 10) >= 3) && ((number % 10) < 4))
		printf ("Three \n");
	if (((number % 10) >= 4) && ((number % 10) < 5))
		printf ("Four \n");
	if (((number % 10) >= 5) && ((number % 10) < 6))
		printf ("Five \n");
	if (((number % 10) >= 6) && ((number % 10) < 7))
		printf ("Six \n");
	if (((number % 10) >= 7) && ((number % 10) < 8))
		printf ("Seven \n");
	if (((number % 10) >= 8) && ((number % 10) < 9))
		printf ("Eight \n");
	if (((number % 10) >= 9) && ((number % 10) < 10))
		printf ("Nine \n");
	}

	return 0;
}