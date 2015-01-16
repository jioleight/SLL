#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

struct node{
	int val;
	char lname[50];
	char fname[50];
	char mname[30];
	char pnum[16];
	char bday[40];
	struct node *next;
};
typedef struct node NODE;
NODE *head = NULL, *curr = NULL;

menu()
{
	clrscr();
	gotoxy(24, 10);
	printf("Phone Book SLL");
	gotoxy(24, 11);
	printf("[1] Insert");
	gotoxy(24, 12);
	printf("[2] Destroy");
	gotoxy(24, 13);
	printf("[3] Remove");
	gotoxy(24, 14);
	printf("[4] Search");
	gotoxy(24, 15);
	printf("[5] Exit");
	gotoxy(24, 16);
	printf("Choice: ");
}

NODE* create(int val)
{	
	NODE *ptr;
	clrscr();
	gotoxy(24, 10);
	printf("Creating NODE @ [%d]", val);
	if(NULL == ptr)
	{
		gotoxy(24, 11);
		printf("Failed to create NODE");
		return NULL;
	}
	ptr->val = val;
	ptr->next;
	head = curr = ptr;
	
	sleep(1);
	return ptr;
}

destroy(NODE *L)
{
	return 0;
}

NODE* insert(int val, char lname[], bool add)
{
	NODE * ptr;
	if(NULL == head)
	{
		return (create(val));
	}
	
	if(add)
	{
		clrscr();
		gotoxy(24, 11);
		printf("Adding to end..");
		sleep(1);
	}
	else
	{
		clrscr();
		gotoxy(24, 11);
		printf("Adding to beginning..");
		sleep(1);
	}
	ptr = (NODE *)malloc(sizeof(NODE));
	if(NULL == ptr)
	{	
		clrscr();
		gotoxy(24, 11);
		printf("Creation failed..");
		sleep(1);
		return NULL;
	}
	ptr->val = val;
	ptr->next = NULL;
	
	if(add)
	{
		curr->next = ptr;
		curr = ptr;
	}
	else
	{
		ptr->next = head;
		head = ptr;
	}
	getch();
	return ptr;
	main();
}
/*
void remove(char *data, NODE *L)
{
	return 0;
}
*/
search(char *data, NODE *L)
{
	return 0;
}

main()
{
	int choice;
	char i, x, lname[50], fname[50], mname[50], pnum[16], bday[40];
	NODE temp, *L;
	clrscr();
	
	menu();
	
	gotoxy(24+9, 16);
	scanf("%i", &choice);
	
	if(i <= 0)
		i++;
	
	switch(choice)
	{
		case 1:
			clrscr();
			gotoxy(24, 10);
			printf("Add new Contact");
			
			gotoxy(24, 11);
			printf("Last Name:");
			gets(temp.lname);
			
			gotoxy(24, 12);
			printf("First Name: ");
			gets(temp.fname);
			
			gotoxy(24, 13);
			printf("Middle Name: ");
			gets(temp.mname);
			
			gotoxy(24, 14);
			printf("Phone Number: ");
			gets(temp.pnum);
			
			gotoxy(24, 15);
			printf("Birthday (MM/DD/YYYY): ");
			gets(temp.bday);
			
			insert(i, lname, true);
			break;
		case 2:
			destroy(L);
			break;
		case 3:
			/*remove(x, L);*/
			break;
		case 4:
			search(x, L);
			break;
		case 5:
			gotoxy(24, 19);
			printf("BYE -BYE!");
			sleep(2);
			return 0;
		default:
			gotoxy(24, 19);
			printf("Invalid choice!");
			main();
			break;
	}
}
