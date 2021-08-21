#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>
struct node
{
	int d,id;
	char n[30];
	float s,ns;
	struct node *next;
}*head=NULL,*tail=NULL;
void insert(int idn,int days,float sal,char s[])
{
	FILE *fptr;
	int a;
	a=(sal/30);
	if(days==30 || days==29)
	{
		a=a*days;
	}
	else
	{
		a=a*(days+1);
	}
	//-----------------------------------------------------
	fptr = fopen("emp.txt", "a");
	fprintf(fptr, "Name    = %s\n", s);
	fprintf(fptr, "Days    = %d\n", days);
	fprintf(fptr, "Salary per month    = %f\n", sal);
	fprintf(fptr, "id    = %d\n", idn);
	fprintf(fptr, "Net Salary    = %d\n", a);
	//-----------------------------------------------------
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	nn->d=days;
	nn->id=idn;
	nn->s=sal;
	nn->ns=a;
	strcpy(nn->n,s);
	if(head==NULL && tail==NULL)
	{
		head=nn;tail=nn;
	}
	else
	{
		tail->next=nn;
		tail=tail->next;
	}
}
//---------------------------------------------------------------------------------
void search(int idn)
{
	int f=0;
	
	if(head==NULL && tail==NULL)
	{
		printf("NO EMPLOYEE TO SEARCH\n");
	}
	else if(head->id==idn)
	{
		printf("YOUR SEARCHED EMPLOYEE NAME :-\t%s\n",head->n);
		printf("YOUR SEARCHED EMPLOYEE id   :-\t%d\n",head->id);
		printf("YOUR SEARCHED EMPLOYEE id   :-\t%f\n",head->ns);
		f=1;
	}
	else if(tail->id==idn)
	{
		printf("YOUR SEARCHED EMPLOYEE NAME :-\t%s\n",tail->n);
		printf("YOUR SEARCHED EMPLOYEE id   :-\t%d\n",tail->id);
		printf("YOUR SEARCHED EMPLOYEE id   :-\t%f\n",tail->ns);
		f=1;
	}
	else
	{
		struct node *temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
				//printf("I am in ---------------------------search metho");
			if(temp->id==idn)
			{
				printf("YOUR SEARCHED EMPLOYEE NAME :-\t%s\n",temp->n);
				printf("YOUR SEARCHED EMPLOYEE id   :-\t%d\n",temp->id);
				printf("YOUR SEARCHED EMPLOYEE NET SALARY   :-\t%f\n",temp->ns);
				break;
			}
		}
		f=1;
	}
	if(f==0)
	{
		printf("NO EMPLYEE WITH THIS ID NUMBER\nCHECK ID NUMBER\n");
	}
}
//---------------------------------------------------------------------------------
int main()
{
	int t,id,d,choice,key;
	char s[30];
	float sal;
	printf("\t\t\t\t\t\t  KLUNIVERSITY  \n");
	printf("\t\t\t\t\t--------------------------------\n");
	printf("\t\t\t\t      --> * PAYROLL MANAGEMENT SYSTEM * <--  \n");
    	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t  *|*MENU*|*\n\t\t 1).REGISTRATION\n\t\t 2).SEARCH\n\t\t 3).EXIT\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	while(1){
	printf("-----------------------------------------------------------------------------------------------------------------------\n");	
	printf("\t\t ENTER YOUR CHOICE:-\n");
	scanf("%d",&choice); 
	if(choice==1)
	{
	
		         printf(" \t\t 1).REGISTRATION\n ");		
				printf("Employee Name:-\n");
				scanf("%s",s);
				printf("Employee id:-\n");
				scanf("%d",&id);
				printf("Employee Salary:-\n");
				scanf("%f",&sal);
				printf("Employee working days:-\n");
				scanf("%d",&d);
				insert(id,d,sal,s);
	}
	else if(choice==2){
	
	        	printf("Enter emp id to search:-\n");
	    		scanf("%d",&key);
   	    		search(key);
	}
	else if(choice==3)	
		exit(0);
	else
		printf("check ur choice");	
	}
}


