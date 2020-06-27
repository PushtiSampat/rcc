

/* ==========================================================================================**
9.  Write a function that will round a floating point number to an indicated decimal place 
	eg: The number 17.457 would yield the 
    value 17.46 when it is rounded off to two decimal places	

==========================================================================================**/


#include<stdio.h>
#include<conio.h>

void round(char[],int);

void main()
{
	char num[10];
	int digits;
	printf("Enter number: ");
	gets(num);
	printf("Enter number of decimal places you want: ");
	scanf("%d",&digits);
	round(num,digits);
	printf("Rounded off number: ");
	puts(num);
	getch();
}


void round(char num[],int digits)
{
	int decimal=0,i=0;
	char *cptr;
	cptr=num;
	while(*cptr != '.')
	{
		i++;
		cptr++;
	}
	if(*(cptr+digits+1)>52 )
	{
		(*(cptr+digits))++;
	}
	*(cptr+digits+1)='\0';
}


/* ==========================================================================================**

output:
Enter number: 23.786
Enter number of decimal places you want: 2
Rounded off number: 23.79

==========================================================================================**/


