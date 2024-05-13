#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rules.h"
#include "user.h"
#include "admin.h"
	
int main()
{	
	
	printf("\t\t\t\t+***********************************************+ \n");
	printf("\t\t\t\t+-----------------------------------------------+ \n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t|                                               |\n");	
	printf("\t\t\t\t|              Welcome to Quiz Game             |\n");
	printf("\t\t\t\t|                                               |\n");
	printf("\t\t\t\t+-----------------------------------------------+ \n");
	printf("\t\t\t\t+***********************************************+ \n");
	printf("\t\t\t\t-->>CREATED BY: GANESH TIWARI \n \t\t\t\t\t        KAPIL TIWARI  \n \t\t\t\t\t\tPABHAT PAUDEL    \n");
	printf("\t\t\t\t+-----------------------------------------------+ \n");
	
	int a,i;
	for(i=0; i<3; i++)	{
	printf("\t\t\t Choose your preference:\n 1. Admin \n 2. User\n");
	scanf("%d",&a);
	if(a==1)
{
	pass();
	admin();
	
	break;
}
	else if(a==2)	{	
	user();
	break;
	}
	else 
	printf("\aEnter 1 or 2: \n\n");	
}
	return 0;
}

int pass()
	{
	{
           int i;
           char ch,password[10],q[10]="admin";
			top:
           printf("Enter password: ");
           for(i=0;i<5;i++)
           {
                      ch= getch();
                      password[i]=ch;
                      ch= '*';
                      printf("%c",ch);                    
           }
           password[i]='\0';
           if((strcmp(password,q))==0)
           {
                      printf("\n\tcorrect");
                      printf("\n\n");                             
           }
           else
           {
                      printf("wrong\n");
                      goto top;    
           }
}
return 0;
}
