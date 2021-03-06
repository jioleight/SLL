#include<stdio.h>

struct pb
{
	char fn[30],mn[30],ln[30],num[30];
	struct pb *n;
};

void create(struct pb ***new, struct pb ***start)
{
	(**new)->n=NULL;
	**start=**new;
}

void insert(struct pb ***new, struct pb *tmp)
{
	(**new)->n=NULL;
	while(1)
	{
		if(tmp->n!=NULL) tmp=tmp->n;
		else break;
	}
	tmp->n=**new;
}

char *search(struct pb **tmp, struct pb **prev, char *srch)
{
	struct pb *t=*tmp,*tprev=*prev;
	char buf[30];
	int m,n=0;
	if(srch==NULL) gets(srch); 
	strcpy(buf,srch);
	printf("\n--------------------\n");
	while(t!=NULL)
	{	m=0;
		if(!strcmp(t->fn,buf)) m=1;  
		if(!strcmp(t->mn,buf)) m=1;
		if(!strcmp(t->ln,buf)) m=1; 
		if(!strcmp(t->num,buf)) m=1;
		if(m)
		{
			n++;
			printf("%s %c. %s",t->fn,t->mn[0],t->ln);
			printf("\n%s\n--------------------\n",t->num);
			if(n==1) 
			{
				*tmp=t; *prev=tprev;
			}
		}
		tprev=t;
		t=t->n;
	}
	if(n==0) *tmp=NULL;
	return buf;
}

void delete(struct pb *tmp, struct pb *prev, struct pb ****start)
{
	strcpy(tmp->fn,NULL);
	strcpy(tmp->mn,NULL);
	strcpy(tmp->ln,NULL);
	strcpy(tmp->num,NULL);
	if(prev==NULL) ***start=tmp->n;
	else 
	{
		prev->n=tmp->n;
		free(tmp);
	}
}

destroy(struct pb ***start, struct pb *tmp)
{
	tmp=**start;
	while(tmp!=NULL)
	{
		delete(tmp,NULL,&start);
		tmp=tmp->n;
	}
}


void Append(struct pb **new, struct pb **start)
{
	char k; int s=0;
	while(!s)
	{	clrscr();
		*new=(struct pb *)malloc(sizeof(struct pb));
		printf("---Add New Contact---\n");
		printf("\nFirst Name: "); gets((*new)->fn);
		printf("Middle Name: "); gets((*new)->mn);
		printf("Last Name: "); gets((*new)->ln);
		printf("Number: "); gets((*new)->num);
		if(*start==NULL) create(&new,&start);
		else insert(&new,*start);
		printf("\nAdd another contact?(y/n) " );
		do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
		if(k=='n'||k=='N') s=1;
	}
}

void Browse( struct pb *start, struct pb *tmp)
{
	char k; 
	int s=0;
	while(!s)
	{
		clrscr(); tmp=start;
		printf("---Browse Contacts---\n");
		printf("\n[1] Search");
		printf("\n[2] Show All");
		printf("\n[3] Back to Main");
		printf("\nChoice? ");
		do k=getche(); while(k!='1'&&k!='2'&&k!='3');	
		if(k=='1')
		{
			printf("\n\nEnter name or number of the contact to search: ");
			search(&tmp,NULL,NULL);
			if(tmp==NULL) 
				printf("\nContact does not exist");
		}
		if(k=='2')
		{
			if(tmp==NULL)
			{
				printf("\n\nEmpty list.");
			}
			else
			{
				printf("\n\n--------------------\n");
				while(tmp!=NULL)
				{
					printf("%s %c. %s",tmp->fn,tmp->mn[0],tmp->ln);
					printf("\n%s\n--------------------\n",tmp->num);
					tmp=tmp->n;
				}	
			}
		}
		if(k=='3') s=1;
		if(!s)
		{
			printf("\nBrowse again?(y/n) " );
			do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
			if(k=='n'||k=='N') s=1;
		}
	}
}

void Change(struct pb *start, struct pb *tmp)
{
	char k,*srch,t[30]; int s=0;
	while(!s)
	{
		clrscr(); tmp=start; srch=NULL;
		printf("---Edit Contact---\n");
		printf("\nEnter name or number of the contact to edit: ");
		do
		{
			if(srch!=NULL) tmp=tmp->n;
			srch=search(&tmp,NULL,srch);
			clrscr();
			if(tmp!=NULL)
			{
				printf("Edit:\n%s %s %s\n%s\n",tmp->fn,tmp->mn,tmp->ln,tmp->num);
				printf("\nare you sure you want the account to be edited?(y/n) ");
				do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
				if(k=='n'||k=='N') k='n'; 
			}
		}	while(k=='n'&&tmp!=NULL);
		if(tmp!=NULL)
		{
			printf("\n\n[1] Edit Name");
			printf("\n[2] Edit Number");
			printf("\n[3] Edit Name and Number");
			printf("\n[4] Back to Main");
			printf("\nChoice? ");
			do k=getche(); while(k!='1'&&k!='2'&&k!='3'&&k!='4');
			printf("\n\nEdit:\n");
			if(k=='1'||k=='3')
			{
				printf("First Name: "); gets(tmp->fn);
				printf("Middle Name: "); gets(tmp->mn);
				printf("Last Name: "); gets(tmp->ln);
			}
			if(k=='2'||k=='3')
			{
				printf("Number: "); gets(tmp->num);
			}
			if(k=='4') s=1;
		}
		else printf("\nContact does not exist");
		if(!s)
		{
			printf("\nEdit another contact?(y/n) " );
			do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
			if(k=='n'||k=='N') s=1;
		}	
	}
}


void Delete(struct pb **start, struct pb *tmp)
{
	char k,*srch,t[30]; int s=0;
	struct pb *prev,***pstart=&start;
	while(!s)
	{
		clrscr(); tmp=*start; srch=NULL; prev=NULL;
		printf("---Delete Contact---\n");
		printf("\n[1] Delete a Contact");
		printf("\n[2] Delete All");
		printf("\n[3] Back to Main");
		printf("\nChoice? ");
		do k=getche(); while(k!='1'&&k!='2'&&k!='3');
		if(k=='1')
		{
			printf("\n\nEnter name or number of the contact to delete: ");
			do
			{
				if(srch!=NULL) 
				{
					prev=tmp;
					tmp=tmp->n;
				}
				srch=search(&tmp,&prev,srch);
				clrscr();
				if(tmp!=NULL)
				{
					printf("Delete:\n%s %s %s\n%s\n",tmp->fn,tmp->mn,tmp->ln,tmp->num);
					printf("\ndelete this contact?(y/n) ");
					do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
					if(k=='n'||k=='N') k='n'; 
				}
			}	while(k=='n'&&tmp!=NULL);
			if(tmp!=NULL)
			{
				printf("\nare you sure you want to delete this contact?(y/n) ");
				do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
				if(k=='n'||k=='N') k='n'; 
				if(k!='n')
				{
					delete(tmp,prev,&pstart);
					printf("\n\ndeleted!");
				}
			}
			else printf("\nContact does not exist");	
		}
		if(k=='2')
		{
			printf("\n\nare you sure you want to delete all contacts?(y/n) ");
			do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
			if(k=='n'||k=='N') k='n'; 
			if(k!='n')
			{
				destroy(&start,tmp);
				printf("\n\ndeleted all contacts!");
			}		
		}
		if(k=='3') s=1;
		if(!s)
		{
			printf("\nDelete another contact?(y/n) " );
			do k=getch(); while(k!='y'&&k!='Y'&&k!='n'&&k!='N');
			if(k=='n'||k=='N') s=1;
		}	
	}
}

main()
{
	int s=1;
	char k=' ';
	FILE *f,*t; 
	struct pb *new=NULL,*start=NULL,*tmp, data; 
	struct pb **pnew=&new,**pstart=&start;
	while(1)
	{
		f=fopen("pb.dat","r");
		while(s!=3)
		{		
			new=(struct pb *)malloc(sizeof(struct pb));
			if((fscanf(f,"%[^\n]\ns \n",(*pnew)->fn))!=EOF)
			{	
				fscanf(f,"%[^\n]\ns \n",(*pnew)->mn);
				fscanf(f,"%[^\n]\ns \n",(*pnew)->ln);
				fscanf(f,"%[^\n]\ns \n\n",(*pnew)->num);
				if(s==1) 
				{
					create(&pnew,&pstart); s=0;
				}
				else insert(&pnew,start);
			}
			else
			{
				free(new); s=3;
			}
		}	fclose(f);
		while(k!='5')
		{
			clrscr(); tmp=start;
			printf("---Phonebook (SLL)---\n");
			printf("\n[1] Add Contact");
			printf("\n[2] Browse Contacts");
			printf("\n[3] Edit Contact");
			printf("\n[4] Delete Contact/s");
			printf("\n[5] Exit");
			printf("\nChoice: ");
			do k=getch();
			while(k!='1'&&k!='2'&&k!='3'&&k!='4'&&k!='5');
			switch(k)
			{
				case '1' : Append(&new,&start); break;
				case '2' : Browse(start,tmp); break;
				case '3' : Change(start,tmp); break;
				case '4' : Delete(&start,tmp); break;
				case '5' : exit(0);
			}
			t=fopen("tmp.dat","a");
			tmp=start;
			while(tmp!=NULL)
			{
				fprintf(t,"%s\n",tmp->fn);
				fprintf(t,"%s\n",tmp->mn);
				fprintf(t,"%s\n",tmp->ln);
				fprintf(t,"%s\n\n",tmp->num);
				tmp=tmp->n;
			}	fclose(t); remove("pb.dat"); rename("tmp.dat","pb.dat");
		}
	}
}
