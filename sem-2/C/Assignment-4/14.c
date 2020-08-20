

// =================================================================
// Q14

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


void display(char *fname,Country c1[],int n)
{
	int i=0;
	FILE *fp;
	
	fp=fopen(fname,"r");
	
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	fseek(fp, 0, SEEK_SET);

	while(fread(&c1[i],sizeof(c1[i]),1,fp))
	{
		printf("\n %d \t %s \t %s \t ",c1[i].id,c1[i].name,c1[i].cp.cp_name);
		i++;
	}
		fclose(fp);
}

void find_country(char *fname,Country c1[],int n)
{
	int i,cnt=0;
	char capi[60];
	FILE *fp;
	
	fp=fopen(fname,"r");
	fseek(fp,0L,0);
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	printf("\n Enter Capital:");
	scanf("%s",capi);
	
	i=0;
	while(fread(&c1[i],sizeof(c1[i]),1,fp))
	{
		if(strcmp(capi,c1[i].cp.cp_name)==0)
		{	
			cnt++;
			printf("\n %d \t %s \t %s \t ",c1[i].id,c1[i].name,c1[i].cp.cp_name);
		}
		i++;
	}
	if(cnt==0)
		printf("\n Record Doesnot Exist...!");

		fclose(fp);
}
void find_capital(char *fname,Country c1[],int n)
{
	int i,cnt=0;
	char cou[60];
	FILE *fp;
	
	fp=fopen(fname,"r");
	fseek(fp,0L,0);
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	printf("\n Enter Country:");
	scanf("%s",cou);
	
	i=0;
	while(fread(&c1[i],sizeof(c1[i]),1,fp))
	{
		if(strcmp(cou,c1[i].name)==0)
		{	
			cnt++;
			printf("\n %d \t %s \t %s \t ",c1[i].id,c1[i].name,c1[i].cp.cp_name);
		}
		i++;
	}
	if(cnt==0)
		printf("\n Record Doesnot Exist...!");

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
	printf("\n 1.Display a Record.");
	printf("\n 2.Determine the capital of a specified ountry.");
	printf("\n 3.Determine the country whose capital is specified.");
	printf("\n --------------------");
	do
	{
		printf("\n Enter Your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n----------------");
					printf("\n Display Records");
					printf("\n-----------------");
					display(file_name,c1,cnt);
					break;
			case 2:
					find_capital(file_name,c1,cnt);
					break;
			case 3:
					find_country(file_name,c1,cnt);
					break;
		}
		printf("\n Do You want to continue:");
		scanf("%s",&choice);

	}while(choice=='y');
	
	getch();
}
/* =========================================================

OUTPUT:

 Enter File name:country.txt

 --------------------
 1.Display a Record.
 2.Determine the capital of a specified ountry.
 3.Determine the country whose capital is specified.
 --------------------
 Enter Your choice:1

----------------
 Display Records
-----------------
 111     India    Delhi
 222     NewZealand Wellington   
 333     Egypt Cairo
 444     Iran Baghdad
 Do You want to continue:y

 Enter Your choice:2

 Enter Country:NewZealand

 222     NewZealand   Wellington
 Do You want to continue:n

 ========================================================= */

