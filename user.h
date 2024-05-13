#include<stdio.h>
#include<time.h>
#include<string.h>
#include "admin.h"
#include<stdlib.h>

	char name[20];
	int count=0;
void user1()
{
	printf("\n\n\t\tUser\n\n");
	int i=1,n,j,opt;
	FILE *fp;
	fp=fopen("question.txt","r");
	while(fread(&q,sizeof(struct quiz),1,fp)==1)
	{
		printf("\t\tQuestion %d",i);
		printf("%d.%s\nOPTIONS:",i,q.quest);
		for(j=0;j<4;j++)
		{
			printf("\n%d.%s",j+1,q.op[j]);
		}
		printf("\nEnter answer:");
		scanf("%d",&opt);
		printf("\n%s",q.ans);
		if(strcmp(q.ans,q.op[opt-1])==0)
		{
			printf("\nCorrect\n");
			count=count+5;
		}
		else
		printf("\nWrong!\n");
		i++;
		fflush(stdin);
		printf("\nScore=%d",count);
	}
	printf("\nFinal Score=%d",count);
	FILE *sc=fopen("score.txt","w+");
	int p;
	fprintf(sc,"%s = %d",name,count);
	fclose(sc);
}
	
void user()	
{
	int i, choice, ans;
	
	FILE *user;
	user=fopen("user.txt","a+");
	
	time_t t;
	time(&t);
	
	printf("Enter your name:\n");
	fflush(stdin);
	scanf("%[^\n]",&name);
	
	
	fprintf(user,"Name : %s \tDate: %s\n",name,ctime(&t));
	fclose(user);
		
	system("cls");
	
		printf("\t\t+-----------------------+\n");
        printf("\t\t|\t   Quiz Game\t|\n");
		printf("\t\t+-----------------------+\n\n");
		printf("\t\t\t Welcome %s\n\n",name);
	
	for (i=1;i<5;i++)
{	
	printf("\n\t\t\t*********************************************** \n");
	printf("\t\t\t 1. Start the game \n");
	printf("\t\t\t 2. View score \n");
	printf("\t\t\t 3. Rules \n");
	printf("\t\t\t 4. Quit \n");
	printf("\t\t\t************************************************ \n");	

	printf("\nPress any number:(1 to 4)\n");
	scanf("%d",&choice);
	switch(choice)
    {
    	case  1:
    		system("cls");
			printf("\t\t+-----------------------+\n");
            printf("\t\t|\tQuiz Game\t|\n");
			printf("\t\t+-----------------------+\n");     
    	user1();
		break;
                
		case 2:
			system("cls");
			printf("\t\t+----------------------+\n");
            printf("\t\t|\tView Score:\t|\n");
			printf("\t\t+----------------------+\n\n");     
			
			FILE *sc;
			sc=fopen("score.txt","r");
			if(sc==NULL)	{
				perror("Unable to open File");
				exit(1);
			}
			char line[100];
			while(fgets(line,sizeof(line),sc))	{
				printf("%s",line);
			}
			
			
			break;
			
        case 3:
        	system("cls");
			printf("\t\t+---------------+\n");
            printf("\t\t|\tRules\t|\n");
			printf("\t\t+---------------+\n");     
			//rules();
            break;
                    
        case 4:
        	system("cls");
			printf("\t\t+-----------------------+\n");
            printf("\t\t|\tThank You\t|\n");
			printf("\t\t+-----------------------+\n");     
			//To quit the game
            exit(0);
            break;
        
	//	default :
    //		break;
	}
}
	exit(0);
}
