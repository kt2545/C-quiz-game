#include<stdio.h>
#ifndef ADMIN_H
#define ADMIN_H
#include<stdlib.h>
#include<string.h>

void update();
struct quiz
{
	char op[4][30],quest[200],ans[30];
}q;

void admin()
{
	printf("\n\n\t\tAdmin\n\n");
	int i,n,j,m,opt;
	for(m=1;m<3;m++)
	{
		printf("choose your preference:\n 1. insert question\n 2.update question\n 3.Exit\n");
		scanf("%d",&m);
		if(m==1)
		{

	FILE *fp;
	fp=fopen("question.txt","a+");
	printf("Enter no of question:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\n\n%d.> Enter question:",i+1);
		scanf("\t%[^\n]",q.quest);
		for(j=0;j<4;j++)
		{
			fflush(stdin);
			printf("Enter answer for option %d:",j+1);
			scanf("%[^\n]",q.op[j]);
		}
		printf("Enter answer(from option):");
		scanf("%d",&opt);
		strcpy(q.ans,q.op[opt-1]);
		fwrite(&q,sizeof(struct quiz),1,fp);
	}
	break;
	}
		else if(m==2)
		{
			system("cls");
			update();
		}
	else	{
		exit(1);
	}
	}
}
void update()
{
    int i=0,choice,j,an;
    char new_quest[100],opt[4][30],answer[30];
    fflush(stdin);
    FILE *fp,*fl;
    fp=fopen("question.txt","rb");
    printf("Choose question to update:");
	while(fread(&q,sizeof(q),1,fp)==1)
	{
		printf("\n%d.%s",i+1,q.quest);
		i++;
		fflush(stdin);
	}
	fclose(fp);
	labe:
	printf("\n:");
	scanf("%d",&choice);
	if(choice<=i)
	{
	printf("\nEnter new question:");
	fflush(stdin);
	scanf("%[^\n]",new_quest);
	{
		for(i=0;i<4;i++)
		{
			printf("\n%d.Enter option:",i+1);
			fflush(stdin);
			scanf("%[^\n]",opt[i]);
		}
		printf("\nEnter answer:");
		scanf("%d",&an);
		if(an<=4 && an>0)
		{
			strcpy(answer,opt[an-1]);
		}
	}
	fp=fopen("question.txt","rb");
	fl=fopen("temp.txt","wb");
	i=0;
	while(fread(&q,sizeof(q),1,fp)==1)
	{
		if((choice-1)==i)
		{
			strcpy(q.quest,new_quest);
			for(j=0;j<4;j++)
			{
				strcpy(q.op[j],opt[j]);
			}
		}
		fwrite(&q,sizeof(q),1,fl);
		i++;
	}
	fclose(fp);
	fclose(fl);
	remove("question.txt");
	rename("temp.txt","question.txt");
}
	else
	{
		printf("Invalid option!!\nENTER AGAIN:");
		goto labe;
	}
}
#endif
