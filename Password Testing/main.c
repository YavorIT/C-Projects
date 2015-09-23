#include <stdio.h>
#include <ctype.h>
#include <Windows.h>


int main () {

	char pass[50];
	int i, flag1=0, flag3=0;

	printf ("Enter a password which don't have any tabs or spaces in it and no more than 50 symbols:\n");
	fgets(pass, 50, stdin);
	pass[strlen(pass) - 1] = '\0';

			for (i=0; i<strlen(pass); i++)
				{
					if (isupper (pass[i]))  {
						flag1++;
						continue;
					} else if  (isdigit (pass[i]))  {
					flag3++;
					continue;
                    }
                }
	if ( flag1>=1 && flag3>=1) {
		printf("Your password is good enough.\n");
	}else {
		printf ("The password you entered is easy to get busted!!!\n");
	}
        system("pause");
	return 0;
}

