
/* ==================================================================
Max-min from Pointer
================================================================== */


#include<stdio.h>

int findmax(int max, int myArray[], int n)
{
	int i;
	int *p = myArray;

	for (i = 1; i < n; ++i) {
		printf("Enter number %02d: ", i + 1);
		scanf("%d",p);
	
		if(*p > max) {
			max  = *p;
		}
		p++;
	
	}
	return max;
}

int main()
{
	int myArray[10], n, i, max;
	int *p = myArray;

	printf("Enter N: ");
	scanf("%d",&n);

	printf("Enter number 01: ");
	scanf("%d",p);

	max = *p;
	max = findmax(max, myArray, n);

	printf("%d is max element\n", max);
	return 0;
}



/* ==================================================================
Output:

	Enter N: 5
	Enter number 01: 10
	Enter number 02: 20
	Enter number 03: 40
	Enter number 04: 30
	Enter number 05: 5
	40 is max element

================================================================== */


