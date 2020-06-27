


/* ==========================================================================================**
10. Write a function using pointers to exchange the value stored in two locations in the memory.
==========================================================================================**/


#include<stdio.h>
#include<conio.h>
void input_data10(int *a,int *b)
{
	int *ptra,*ptrb;
	ptra=a;
	ptrb=b;
	printf("Enter Number 1 : ");
	scanf("%d",ptra);
	printf("Enter Number 2 : ");
	scanf("%d",ptrb);
}
void disp_data10(int a,int b)
{
	printf("\nA = %d",a);
	printf("\nB = %d\n",b);
}
void swap(int *a,int *b)
{
	int *ptra,*ptrb;
	int temp;
	ptra=a;
	ptrb=b;
	temp=*ptra;
	*ptra=*ptrb;
	*ptrb=temp;

}

int main()
{
	int a=0,b=0;

	input_data10(&a,&b);

	printf("\tBEFORE SWAP");
	
	disp_data10(a,b);
	
	swap(&a,&b);
	
	printf("\tAFTER SWAP");
	
	disp_data10(a,b);

	return 0;
}

 /* ==========================================================================================**
output:

Enter Number 1 : 10
Enter Number 2 : 20

        BEFORE SWAP

A = 10
B = 20

        AFTER SWAP

A = 20
B = 10

==========================================================================================* */