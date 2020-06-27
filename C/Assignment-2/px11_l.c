/*==========================================================================================**
11_L.	Sort an array of string.	

==========================================================================================**/


#include<stdio.h>
#include<string.h>

void readnames(char names[][20],int limit)
{
	char (*cptr)[20];
	int i;
	cptr=names;
	fflush(stdin);
	printf("Enter %d names: \n",limit);
	for(i=0;i<limit;i++)
	{
		gets(*(cptr+i));
	}
}

void sort(char names[][20],int limit)
{
	char (*cptr)[20],min[20];
	int i,index,j;

	cptr=names;

	for(i=0;i<limit-1;i++)
	{
		strcpy(min,*(cptr+i));
		index=i;

		for(j=i+1;j<limit;j++)
		{
			if(strcmp(min,*(cptr+j))>0)
			{
				strcpy(min,*(cptr+j));
				index=j;
			}
			
		}
		strcpy(*(cptr+index),*(cptr+i));
		strcpy(*(cptr+i),min);
	}

}
void print(char names[][20],int limit)
{
	char (*cptr)[20];
	int i;
	cptr=names;
	printf("Sorted names:\n");
	for(i=0;i<limit;i++)
	{
		puts(*(cptr+i));
	}
}

int main()
{
	char names[5][20];
	int limit;

	printf("How many names you have: ");
	scanf("%d",&limit);
	
	readnames(names,limit);
	
	sort(names,limit);
	
	print(names,limit);
	
	return 0;
}



/* ==========================================================================================**

Enter 3 names:
ajinkya
thindo
jinki
Sorted names:
ajinkya
jinki
thindo

==========================================================================================**/




