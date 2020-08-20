
// ==========================================================================================**
// 8. Write function that receives a sorted array of integers and an integer value, 
// and inserts the value in correct place.	
// ==========================================================================================**

#include<stdio.h>
#include<conio.h>

void readnum(int[],int,int*);
void addnum(int[],int*,int*);
void display(int[],int);

void main()
{
	int num[10],limit,n=0;
	printf("Enter how many numbers are in your array: ");
	scanf("%d",&limit);
	readnum(num,limit,&n);
	addnum(num,&limit,&n);
	display(num,limit);
	getch();
}

void readnum(int num[],int limit,int *new_num)					//passing the number which user want ot add in a pointer so 
{										//it can be used in other function without returning from here..
	int i,*iptr;
	iptr=num;
	printf("Enter %d sorted numbers: ",limit);

	for(i=0;i<limit;i++)
	{
		scanf("%d",iptr);
		iptr++;
	}
		printf("Enter number to add in your sorted array: ");
		scanf("%d",new_num);
	
}

void addnum(int num[],int *new_limit,int *new_num)				//Again passing address of limit and new number..
{
	int *iptr,i,j,flag=0;
	iptr=num;
	for(i=0;i<*new_limit;i++)
	{
		if(*new_num < *(iptr+i))					//finding the greater number than our number so we can add new number in the sorted array
		{
			for(j=*(new_limit)-1;j>=i;j--)
			{
				*(iptr+j+1)=*(iptr+j);
			}
			*(iptr+i)=*new_num;
			(*new_limit)++;						//increasing limit by 1
			flag=1;
			break;
		}	
	}
	if(!flag)								//if flag is off that means new number is gretest among sorted array..
	{
		*(iptr+i)=*new_num;
		*new_limit=*new_limit+1;
	}
}

void display(int num[],int limit)
{
	int i,*iptr;

	iptr=num;
	printf("New Array: \n");
	for(i=0;i<limit;i++)
	{
		printf("%d ",*iptr);
		iptr++;
	}
}

/* ==========================================================================================**
// output:

Enter how many numbers are in your array: 5
Enter 5 sorted numbers: 10 20 30 50 60
Enter number to add in your sorted array: 40
New Array:
10 20 30 40 50 60

// ==========================================================================================*/


