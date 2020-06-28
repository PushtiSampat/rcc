

// =================================================================
// Q13

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Country
{
	int id;
	char name[60];
	struct capital
	{
		char cp_name[60];
	};
	struct capital cp;
};

void Insert(char *fname,struct Country c1[],int n)
{
	int i;
	FILE *fp;
	fp=fopen(fname,"a");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		printf("\n Enter Country id:");
		scanf("%d",&c1[i].id);

		fflush(stdin);
		printf(" Enter Country Name:");
		scanf("%s",&c1[i].name);
		
		fflush(stdin);
		printf(" Enter Capital Name:");
		scanf("%s",&c1[i].cp.cp_name);

		printf("\n %d \t %s \t %s ",c1[i].id,c1[i].name,c1[i].cp.cp_name);
		fwrite(&c1[i], sizeof(c1[i]), 1, fp);
	}
}

void display(char *fname,struct Country c1[],int n)
{
	int i;
	FILE *fp;
	
	fp=fopen(fname,"r");
	fseek(fp,0L,0);
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	for(int i=0;i<n;i++)
	{
		fread(&c1[i],sizeof(c1[i]),1,fp);
		printf("\n %d \t %s \t %s \t ",c1[i].id,c1[i].name,c1[i].cp.cp_name);
	}
		fclose(fp);
}

void main()
{
	int n,ch,res;
	char file_name[80],choice='n',name[20],tele[10];
	static int cnt=0;
	struct Country c1[10];

	
	printf("\n Enter File name:");
	scanf("%s",&file_name);
	printf("\n --------------------");
	printf("\n 1.Add a new Record.");
	printf("\n 2.Display a Record. ");
	printf("\n --------------------");
	do
	{
		printf("\n Enter Your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n Enter number of records for Add:");
					scanf("%d",&n);
					cnt=cnt+n;
					Insert(file_name,c1,n);
					break;
			case 2:
					printf("\n----------------");
					printf("\n Display Records");
					printf("\n-----------------");
					display(file_name,c1,cnt);
					break;
		}
		printf("\n Do You want to continue:");
		scanf("%s",&choice);

	}while(choice=='y');
	
	getch();
}


// ============
// OUTPUT
// ============

//  Enter File name:country.txt

//  --------------------
//  1.Add a new Record.
//  2.Display a Record.
//  --------------------
//  Enter Your choice:1

//  Enter number of records for Add:3

//  Enter Country id:1
//  Enter Country Name:India
//  Enter Capital Name:Delhi

//  Enter Country id:2
//  Enter Country Name:Spain
//  Enter Capital Name:Madrid

//  Enter Country id:3
//  Enter Country Name:Canada
//  Enter Capital Name:Ottawa

//  Do You want to continue:y

//  Enter Your choice:2

// ----------------
//  Display Records
// -----------------
//  1     India   Delhi
//  2     Spain   Madrid
//  3     Canada Ottawa

//  Do You want to continue:n


// =================================================================