#include "MyHeader.h"




int main()
{
	start:
    printf ("\n\n\t\tChoose the option you want\n\n\n");
    menu ();
	goto start;
    return 0;
}




void menu (){

    int UserChoice;

    printf ("1. Adding new painting to the gallery.\n");
    printf ("2. Deleting painting's data.\n");
    printf ("3. Listing all paintings sorted by author and price.\n");
    printf ("4. Updating painting's information.\n");
	printf ("5. Exit.\n");


    printf ("\nYour choice is:  ");
    scanf ("%d", &UserChoice);
    fflush(stdin);
    printf ("\n");
    choiceManage(UserChoice);
}


void choiceManage(int choice){

    switch (choice){
    case 1:
            addPainting();
        break;
    case 2:
            Reading(choice);
        break;
    case 3:
			Reading(choice);
        break;
    case 4:
			Reading(choice);
        break;
	case 5:
            system ("Pause");
			exit(1);
			break;
	default:
		printf ("\nYou have selected invalid option!\n");
		break;
    }
}


