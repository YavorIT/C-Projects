#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50
#define LENGHT 25

 typedef struct List {

    char code[LENGHT];
    char AuthorName [SIZE];
    char PaintingName [SIZE];
    double Price;
    int year;

    struct List *next;
}Painting;


void menu ();
void choiceManage (int choice);
void addPainting();
void deletePainting(Painting **head);
void PrintAllPaintings(Painting **head);
void updatePainting(Painting **head);
void Writing (Painting *listPainting, int choice);
void Reading (int choice);
Painting *list_switch( Painting *l1, Painting *l2 );
Painting *FreeAll(Painting **head);



void addPainting (){

    Painting *current, *head;
    int i = 0;
    char c;
        head = NULL;

    do{

        if ((current = (Painting *) malloc (sizeof(Painting)))== NULL){
            printf ("\nError allocating memory!!!");
            exit (2);
        }
                printf ("\nEnter the data of the %d painting:\n", i + 1);
            printf ("\nEnter the code of the painting: ");
                fgets (current->code, LENGHT, stdin);
                    current->code[strlen(current->code) - 1] = '\0';
            fflush(stdin);

            printf ("\nEnter the author of the painting: ");
                fgets (current->AuthorName, SIZE, stdin);
                   current->AuthorName[(strlen(current->AuthorName) - 1)] = '\0';
            fflush(stdin);

            printf ("\nEnter the name of the painting: ");
                fgets (current->PaintingName, SIZE, stdin);
                    current->PaintingName[strlen(current->PaintingName) - 1] = '\0';
            fflush(stdin);

            printf ("\nEnter the painting's price: ");
                scanf ("%lf", &current->Price);
            fflush(stdin);

            printf ("\nEnter the painting's year: ");
                scanf("%d", &current->year);
            fflush(stdin);

            current->next = head;
            head = current;
            i++;
            printf ("\nDo you want to add another painting?  (Y\\N): ");
                scanf("%c", &c);
            fflush(stdin);
    }while (c != 'n' && c != 'N');

    current = head;

    Writing(current, 1);
}


void deletePainting(Painting **head){

    Painting  *localHead, *temp;
    char CodetoDelete[LENGHT], ch;
    int i = 0;

    localHead = *head;
	temp = *head;

	printf ("\nPictures you have in the gallery.\n\n");

          printf ("------------------------------\n");
        while(*head){

            printf ("Code: %s\n", (*head)->code);
            printf ("Author: %s\n", (*head)->AuthorName);
            printf ("Painting: %s\n", (*head)->PaintingName);
            printf ("Price: %.2lf\n", (*head)->Price);
            printf ("Year: %d\n", (*head)->year);
            printf ("------------------------------");
            printf ("\n");

            *head = (*head)->next;
        }
        *head = temp;
deleting:

		localHead = *head;
		 temp = *head;
		 *head = temp;
        printf ("\nEnter the code of the painting you want to delete: ");
            scanf ("%s", CodetoDelete);
        fflush(stdin);
            CodetoDelete[strlen(CodetoDelete)] = '\0';
			i = 0;
            while (temp){

				if (!strcmp(CodetoDelete, temp->code)){
						if (i == 0){
							*head = (*head)->next;
							localHead = *head;
							i++;
							break;
						}else {
							(*head)->next = temp->next;
							temp = temp->next;
						}
				}else {
					temp = temp->next;
					if(i != 0){
                        *head = (*head)->next;
					}
				}
				if (temp == NULL)
					printf ("\nThere's not a painting with such a code!\n");
				i++;
            }
			*head = localHead;

			printf ("\nPictures after the Deleting.\n");
			printf ("------------------------------\n");

              while(*head){

            printf ("Code: %s\n", (*head)->code);
            printf ("Author: %s\n", (*head)->AuthorName);
            printf ("Painting: %s\n", (*head)->PaintingName);
            printf ("Price: %.2lf\n", (*head)->Price);
            printf ("Year: %d\n", (*head)->year);
            printf ("------------------------------");
            printf ("\n");

            *head = (*head)->next;

        }
			 *head = localHead;

			 printf ("Do you want to delete another painting? (Y\\N): ");
				scanf ("%c",  &ch);
			fflush(stdin);
		if ((ch == 'y') || (ch == 'Y'))
				goto deleting;

			 if ((remove("Paintings.bin")) != 0){
					printf ("Error deleting the old file.");
					exit(3);
			}

    Writing(*head, 2);
}




void updatePainting(Painting **head){

	char PaintingtoUpdate[LENGHT], ch;
	Painting *temp;
	int userChoice;

	temp = *head;

	printf ("\nPictures you have in the gallery.\n\n");

          printf ("------------------------------\n");
        while(*head){

            printf ("Code: %s\n", (*head)->code);
            printf ("Author: %s\n", (*head)->AuthorName);
            printf ("Painting: %s\n", (*head)->PaintingName);
            printf ("Price: %.2lf\n", (*head)->Price);
            printf ("Year: %d\n", (*head)->year);
            printf ("------------------------------");
            printf ("\n");

            *head = (*head)->next;
        }
updating:

		*head = temp;

		printf ("\nEnter the code of the painting you want to update: ");
		fgets (PaintingtoUpdate, LENGHT, stdin);
			PaintingtoUpdate[strlen(PaintingtoUpdate) - 1] = '\0';
			fflush(stdin);

	while (*head){
		if (!strcmp(PaintingtoUpdate, (*head)->code))
		{
			do {
				printf ("\nWhat do you want to change? \n\n\n");
				printf ("1. Painting's code.\n");
				printf ("2. Painting's author.\n");
				printf ("3. Painting's name.\n");
				printf ("4. Painting's Price.\n");
				printf ("5. Painting's year.\n");
				printf ("Your choice is: ");
					scanf("%d", &userChoice);
				fflush(stdin);

				switch (userChoice){
				case 1:
					printf ("\nEnter the new code of the painting: ");
						fgets ((*head)->code, LENGHT, stdin);
						  (*head)->code[strlen((*head)->code) - 1] = '\0';
					fflush (stdin);
					printf ("\nDo you want to change something else? (Y\\N): ");
						scanf("%c", &ch);
					fflush(stdin);
					continue;
				case 2:
					printf ("\nEnter the new author of the painting: ");
						 fgets ((*head)->AuthorName, SIZE, stdin);
						 (*head)->AuthorName[(strlen((*head)->AuthorName) - 1)] = '\0';
					fflush (stdin);
					printf ("\nDo you want to change something else? (Y\\N): ");
						scanf("%c", &ch);
					fflush(stdin);
					continue;
				case 3:
					printf ("\nEnter the new name of the painting: ");
						fgets ((*head)->PaintingName, SIZE, stdin);
							(*head)->PaintingName[(strlen((*head)->PaintingName) - 1)] = '\0';
					fflush (stdin);
					printf ("\nDo you want to change something else? (Y\\N): ");
						scanf("%c", &ch);
					fflush(stdin);
					continue;
				case 4:
					printf ("\nEnter the new price of the painting: ");
						scanf ("%lf", &(*head)->Price);
					fflush (stdin);
					printf ("\nDo you want to change something else? (Y\\N): ");
						scanf("%c", &ch);
					fflush(stdin);
					continue;
				case 5:
					printf ("\nEnter the new year of the painting: ");
						scanf ("%d", &(*head)->year);
					fflush (stdin);
					printf ("\nDo you want to change something else? (Y\\N): ");
						scanf("%c", &ch);
					fflush(stdin);
					continue;
				}
			}while ((ch != 'n') && (ch != 'N'));

			break;
		}else {
			*head = (*head)->next;
		}
	}

	*head = temp;

	printf ("\nPictures after the update.\n");
	printf ("------------------------------\n");

	while(*head){

            printf ("Code: %s\n", (*head)->code);
            printf ("Author: %s\n", (*head)->AuthorName);
            printf ("Painting: %s\n", (*head)->PaintingName);
            printf ("Price: %.2lf\n", (*head)->Price);
            printf ("Year: %d\n", (*head)->year);
            printf ("------------------------------");
            printf ("\n");

            *head = (*head)->next;
        }

	*head = temp;

	printf ("\nDo you want to update another painting? (Y\\N): ");
		scanf("%c", &ch);
	fflush(stdin);

if ((ch == 'y') || (ch == 'Y'))
	goto updating;

			if (remove("Paintings.bin") != 0){
					printf ("Error deleting the old file.");
					exit(4);
			}

    Writing(*head, 4);
}


void PrintAllPaintings(Painting **head){

	Painting *p, *q, *top;
    int flag = 1;



    if( (top = (Painting *) malloc(sizeof(Painting))) == NULL) {
       printf ("Memory Allocation error.\n");
        exit(23);
    }

    top->next = *head;
		if( *head != NULL && (*head)->next != NULL ) {

        while( flag ) {

            flag = 0;
            q = top;
            p = top->next;
            while( p->next != NULL ) {

				if( (strcmp(p->AuthorName,  p->next->AuthorName)) > 0) {
                    q->next = list_switch( p, p->next );
                    flag = 1;
                }else if( (strcmp(p->AuthorName,  p->next->AuthorName)) == 0){

					if (p->Price < p->next->Price){
						 q->next = list_switch( p, p->next );
						flag = 1;
					}
				}

                q = p;

				if( p->next != NULL )
                    p = p->next;
            }
        }
    }
    p = top->next;
	*head = p;

    free(top);

		printf ("\nSorted list is:\n\n");

	while(*head){

            printf ("Code: %s\n", (*head)->code);
            printf ("Author: %s\n", (*head)->AuthorName);
            printf ("Painting: %s\n", (*head)->PaintingName);
            printf ("Price: %.2lf\n", (*head)->Price);
            printf ("Year: %d\n", (*head)->year);
            printf ("------------------------------");
            printf ("\n");

            *head = (*head)->next;
        }
        *head = p;
        p = FreeAll(&(*head));
        free(p);
}



Painting *list_switch( Painting *l1, Painting *l2 )
{
    l1->next = l2->next;
    l2->next = l1;
    return l2;
}


void Writing (Painting *listPainting, int choice){

    FILE *fp;
    Painting *temp;
    int i, j, k;


    temp = listPainting;

    if ((fp = fopen ("Paintings.bin", "ab")) == NULL){

        printf ("\nError opening file for adding");
        exit(5);
    }

    while (temp){

        i = sizeof(temp->AuthorName);
        j = sizeof(temp->PaintingName);
        k = sizeof(temp->code);


        if  ((fwrite (&k, sizeof(int), 1, fp)) != 1){
        printf ("\nError writing in file!");
        exit (6);
       }
       if  ((fwrite (&temp->code, sizeof(char), k, fp)) != k){
        printf ("\nError writing in file!");
        exit (7);
       }
       if  ((fwrite (&i, sizeof(int), 1, fp)) != 1){
        printf ("\nError writing in file!");
        exit (8);
       }
       if  ((fwrite (&temp->AuthorName, sizeof(char), i, fp)) != i){
        printf ("\nError writing in file!");
        exit (9);
       }
       if  ((fwrite (&j, sizeof(int), 1, fp)) != 1){
        printf ("\nError writing in file!");
        exit (10);
       }
       if  ((fwrite (&temp->PaintingName, sizeof(char), j, fp)) != j){
        printf ("\nError writing in file!");
        exit (11);
       }
       if  ((fwrite (&temp->Price, sizeof(double), 1, fp)) != 1){
        printf ("\nError writing in file!");
        exit (12);
       }
       if  ((fwrite (&temp->year, sizeof(int), 1, fp)) != 1){
        printf ("\nError writing in file!");
        exit (13);
       }

       temp = temp->next;
    }

    fclose(fp);
	if (choice == 1)
		 printf ("\nWriting successful.\n");
	 if (choice == 2)
		 printf ("\nDeleting successful.\n");
	if (choice == 4)
		 printf ("\nUpdating successful.\n");


    temp = FreeAll(&temp);
    free(temp);
}



void Reading(int choice){

    FILE *fp;
    Painting *curr, *first;
    int i, j, k;

    first = NULL;

        if ((fp = fopen ("Paintings.bin", "rb")) == NULL){
                printf ("\nError opening file for reading!\n");
                system("Pause");
                exit (14);
        }

    while (1){

        if ((curr = (Painting *) malloc (sizeof(Painting))) == NULL){
            printf ("\nError allocating memory!");
            exit (15);
        }

        if  ((fread (&k, sizeof(int), 1, fp)) != 1){
            free(curr);
            break;
       }

      if  ((fread (&curr->code, sizeof(char), k, fp)) != k){
        printf ("\nError reading from file1!");
        exit (16);
       }

         if  ((fread (&i, sizeof(int), 1, fp)) != 1){
        printf ("\nError reading from file2!");
        exit (17);
       }

       if  ((fread (&curr->AuthorName, sizeof(char), i, fp)) != i){
        printf ("\nError reading from file2!");
        exit (18);
       }

         if  ((fread (&j, sizeof(int), 1, fp)) != 1){
        printf ("\nError reading from file2!");
        exit (3);
       }

       if  ((fread (&curr->PaintingName, sizeof(char), j, fp)) != j){
        printf ("\nError reading from file3!");
        exit (19);
       }

       if  ((fread (&curr->Price, sizeof(double), 1, fp)) != 1){
        printf ("\nError reading from file4!");
        exit (20);
       }

       if  ((fread (&curr->year, sizeof(int), 1, fp)) != 1){
        printf ("\nError reading from file5!");
        exit (21);
       }

        curr->next = first;
        first = curr;
    }

    fclose (fp);
    curr = first;

    printf ("\nReading successful.\n");

	if (choice == 2)
        deletePainting(&curr);
	if (choice == 3)
		PrintAllPaintings(&curr);
	if (choice == 4)
		updatePainting(&curr);
}

Painting *FreeAll (Painting **head){

    Painting *temp, *p;

        for (temp = *head; temp != NULL;){

            p = temp;
            temp = temp->next;
            free(p);
        }
        *head = NULL;
        return *head;
}

