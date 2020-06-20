// struct1
#include<stdio.h>
#include<stdlib.h>

void func1(int *p)
{
	printf("\nfunc1(int *p)\n");
	printf("> %d ----- p\n", p); // Address of 'a' (300)
	printf("> %d ----- *p\n", *p); // Value of 'a' (10)
	
	printf("> %d ----- &p\n", &p); // Address(of this function) of 'p' (2272)
	// (it is not necessary that it will same of func1 and func2 and func3) 	 
}


void func2(int p)
{
	printf("\nfunc2(int p)\n");
	printf("> %d ----- p\n", p); // Value of 'a' (10)
	// printf("%d\n", *p); // Error

	printf("> %d ----- &p\n", &p); // Address(of this function) of 'p' (2272)
	// (it is not necessary that it will same of func1 and func2 and func3) 	 
}

void func3(int **p)
{
	printf("\nfunc3(int **p)\n");
	printf("> %d ----- p\n", p); // Address of p (2296)
	printf("> %d ----- *p\n", *p); // Value of 'p' OR Address of 'a' 2300	
	
	printf("> %d ----- &p\n", &p); //// Address(of this function) of 'p' (2272)
	// (it is not necessary that it will same of func1 and func2 and func3) 	 

}

// Driver Code
int main()
{

	int a = 10;
	int *p = &a;	

	printf("Main\n");
	printf("> %d\n", p); // Address of 'a' OR Value of 'p' (2300)
	printf("> %d\n", *p); // Value of 'a' (10)
	printf("> %d\n", &p); // Address(of this function) of 'p' (2296)

	func1(p); //
	func2(*p);
	func3(&p);

	return 0;
}