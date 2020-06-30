


/* ================================================================
 Q.10
 Write a program that will generate a data file containing the 
 list of  customers and their corresponding telephone numbers.
 Use a structure  variable to store the name and 
 telephone number of each customer. 
 Create  a data file using a sample list. 
 ================================================================ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customers
{
	char name[60],telephone[10];
};

void getdata(char *fname, struct customers cu[],int n)
{
	int i;
	FILE *fp;
	fp=fopen(fname,"w");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\n Enter Name of Customer:");
		gets(cu[i].name);
		fflush(stdin);
		printf(" Enter Telephone No:");
		scanf("%[^\n]",&cu[i].telephone);
	
		fprintf(fp,"%s \t %s \n",cu[i].name,cu[i].telephone);
	}
		fclose(fp);
}

void displayR(char *fname,struct customers cu[],int n)
{
	int i;
	FILE *fp;
	fp=fopen(fname,"r");
	if(fp==NULL)
	{
		printf("\n Error in opening an file...");
		exit(0);
	}

	for(int i=0;i<n;i++)
	{
		fscanf(fp,"%s",&cu[i].name);
		fscanf(fp,"%s",&cu[i].telephone);
	
		printf("\n %s \t %s",cu[i].name,cu[i].telephone);
	}
		fclose(fp);
}


int main()
{
	int n;
	char file_name[80];

	struct customers cu[10];

	printf("\n Enter File name: ");
	scanf("%s",&file_name);

	printf("\n enter number of records: ");
	scanf("%d",&n);

	getdata(file_name,cu,n);

	printf("\n ====== Display Records ======");

	displayR(file_name,cu,n);

	return 0;

}

/* ==========================================================
Output:


	 Enter File name: records.txt

	 enter number of records: 2

	 Enter Name of Customer:Ajinkya
	 Enter Telephone No:96387

	 Enter Name of Customer:Steffi
	 Enter Telephone No:78954

	 ====== Display Records ======
	 Ajinkya         96387
	 Steffi          78954
	 
 ========================================================== */


// =================================================================

