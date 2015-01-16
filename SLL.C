#include<stdlib.h>
#include<stdio.h>

struct list_el {
   int val;
   struct list_el * next;
};

typedef struct list_el item;

void main() {
   item * curr, * head;
   int i, data;
   
   clrscr();

   head = NULL;

   for(i=1;i<=10;i++) {
      curr = (item *)malloc(sizeof(item));
      curr->val = i;
      curr->next  = head;
      head = curr;
   }

   curr = head;
   
   printf("\n\nEnter #: ");
   scanf("%i", &data);
   
   curr = (item *)malloc(sizeof(item));
   curr->val = data;
   curr->next = head;
   head = curr;
   
   while(curr) 
   {
      printf("%d\n", curr->val);
      curr = curr->next ;
   }
   
   getch();
   
}