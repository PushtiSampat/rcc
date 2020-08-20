

// =================================================================
// Q12

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Employee
{
	int empno;
	char name[20],address[50],phone[20];
	double salary;
};


void getdata(char *fname,struct Employee e1[],int n)
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
		fflush(stdin);
		printf("\n Enter Employee ID: ");
		scanf("%d", &e1[i].empno);
		printf(" Enter Employee name: ");
		scanf("%s",&e1[i].name);
		fflush(stdin);
		printf(" Enter Employee address: ");
		scanf("%s",&e1[i].address);
		printf(" Enter phone number:");
		fflush(stdin);
		scanf("%s",&e1[i].phone);
		printf(" Enter Salary:");
		fflush(stdin);
		scanf("%lf",&e1[i].salary);
		
		fwrite(&e1[i], sizeof(e1[i]), 1, fp);

	//	fprintf(fp,"\n %d \t %s \t %f",e1[i].empno,e1[i].name,e1[i].salary);
	}
		fclose(fp);
}

void display_namewise(char *fname,struct Employee e1[],int n)
{
	int i,cnt=0;
	char name[20];

	FILE *fp;
	
	fp=fopen(fname,"r");
	fseek(fp,0L,0);
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	printf("Enter Name:");
	scanf("%s",name);
	
	for(int i=0;i<n;i++)
	{

		fread(&e1[i],sizeof(e1[i]),1,fp);
		if(strcmp(name,e1[i].name)==0)
		{
			cnt++;
			printf("\n %d \t %s \t %s \t %s \t %lf",e1[i].empno,e1[i].name,e1[i].address,e1[i].phone,e1[i].salary);	
		}
		
	}
	if(cnt==0)
		printf("\n Recored Doesent exist");
	fclose(fp);
}

void display(char *fname,struct Employee e1[],int n)
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
		fread(&e1[i],sizeof(e1[i]),1,fp);
		printf("\n %d \t %s \t %s \t %s \t %lf",e1[i].empno,e1[i].name,e1[i].address,e1[i].phone,e1[i].salary);
	}
		fclose(fp);
}

void modify(char *fname,struct Employee e1[],int n)
{
	int i,empid,cnt=0;
	double sal;
	char name[20];
	FILE *fp,*fptr;
	
	fp=fopen(fname,"r");
	
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	fptr=fopen("temp.txt","w");
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	printf("\n Enter Employee Id:");
	scanf("%d",&empid);

	for(int i=0;i<n;i++)
	{
		fread(&e1[i],sizeof(e1[i]),1,fp);
	
		if(e1[i].empno==empid)
		{
			cnt++;
			fflush(stdin);
			printf("\nEnter Employee ID: ");
			scanf("%d", &e1[i].empno);
			printf(" Enter Employee name: ");
			scanf("%s",&e1[i].name);
			fflush(stdin);
			printf(" Enter Employee address: ");
			scanf("%s",&e1[i].address);
			printf(" Enter phone number:");
			fflush(stdin);
			scanf("%s",&e1[i].phone);
			printf(" Enter Salary:");
			fflush(stdin);
			scanf("%lf",&e1[i].salary);
			
			fwrite(&e1[i], sizeof(e1[i]), 1, fptr);
		}
		else
		{
			fwrite(&e1[i], sizeof(e1[i]), 1, fptr);
		}
	}
	if(cnt>0)
		printf("\n Employee Edited Successfully.");
	else
		printf("\n Employee Not Exist...!!");

	
	fclose(fp);
	fclose(fptr);

	fp=fopen(fname,"w");

	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	fptr=fopen("temp.txt","r");
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	for(int i=0;i<n;i++)
	{
		fread(&e1[i],sizeof(e1[i]),1,fptr);
		fwrite(&e1[i], sizeof(e1[i]), 1, fp);
	}
	
		fclose(fp);
		fclose(fptr);
		
}

int removeR(char *fname,struct Employee e1[],int n)
{
	int i,empid,cnt=0;
	double sal;
	char name[20];
	FILE *fp,*fptr;
	
	fp=fopen(fname,"r");
	
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	fptr=fopen("temp.txt","w");
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	printf("\n Enter Employee Id:");
	scanf("%d",&empid);

	for(int i=0;i<n;i++)
	{
		fread(&e1[i],sizeof(e1[i]),1,fp);
	
		if(e1[i].empno==empid)
		{
			cnt++;
		}
		else
		{
			fwrite(&e1[i], sizeof(e1[i]), 1, fptr);
		}
	}
	if(cnt>0)
		printf("\n Employee Deleted Successfully.");
	else
		printf("\n Employee Not Exist...!!");

	
	fclose(fp);
	fclose(fptr);

	fp=fopen(fname,"w");

	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	
	fptr=fopen("temp.txt","r");
	if(fp==NULL)
	{
		printf	("\n Error in opening an file...");
		exit(0);
	}
	for(int i=0;i<n;i++)
	{
		fread(&e1[i],sizeof(e1[i]),1,fptr);
		fwrite(&e1[i], sizeof(e1[i]), 1, fp);
	}
	
		fclose(fp);
		fclose(fptr);
		if(cnt>0)
			return 1;
		else
			return 0;
		
}

int main()
{
	int n,ch,res;
	char file_name[80],choice='n',name[20],tele[10];
	int cnt=0;
	struct Employee e1[10];

	printf("\n Enter File name:");
	scanf("%s",&file_name);
	do
	{
		printf("\n\n 1.Add a new record.");
		printf("\n 2.Delete a record. ");
		printf("\n 3.Modify an existing record.");
		printf("\n 4.Retrieve and display an entire record for a given name.");
		printf("\n 5.Generate a complete list of all names, addresses and telephone numbers.\n");

		printf("\n Enter Your choice:");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("\n Enter number of records to Add:");
					scanf("%d",&n);
					cnt=cnt+n;
					getdata(file_name,e1,n);
					break;
			case 2:
					res=removeR(file_name,e1,cnt);
					// int remove(char *fname,struct Employee e1[],int n)

					if(res)
						cnt=cnt-1;
					break;
			case 3:
					modify(file_name,e1,cnt);
					break;
			case 4:
					display_namewise(file_name,e1,cnt);
					break;
			case 5:
					printf("\n Display Records");
					display(file_name,e1,cnt);
					break;
		}
		printf("\n Do You want to continue:");
		scanf("%s",&choice);
		

	}while(choice=='y');
	
	return 0;
}



// =================================================================


