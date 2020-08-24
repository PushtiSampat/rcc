/* ===========================================================
 
 * Roll No: 30
 * 
 * File:      fibonacci_using_recursion.cpp
 * Copyright: 21-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to find Fibonacci using Recursion
 * 
 * ========================================================== */

#include <iostream>

int fibonacci(int n) 
{ 
    if (n <= 1) 
        return n; 
    return fibonacci(n-1) + fibonacci(n-2); 
} 

// Driver code
int main()
{
	int num;

    std :: cout << "Which Fibonacci num you want: ";
    std :: cin >> num;

    std :: cout << fibonacci(num) << std :: endl;

	return 0;
}


/* ===========================================================
Output:
    Which Fibonacci num you want: 8
    21
 
 * ========================================================== */

