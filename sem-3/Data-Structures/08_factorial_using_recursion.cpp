/* ===========================================================
 
 * Roll No: 30
 * 
 * File:      factorial_using_recursion.cpp
 * Copyright: 21-Aug-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:  Write a program to find Factorial using Recursion
 * 
 * ========================================================== */

#include <iostream>

int factorial(int num)
{
	if (num == 0) return 1;
	return num * factorial(num - 1);
}

// Driver code
int main()
{
	int num;

    std :: cout << "Enter num: ";
    std :: cin >> num;

    std :: cout << factorial(num) << std :: endl;

	return 0;
}


/* ===========================================================
Output:

    Enter num: 5
    120
 
 * ========================================================== */
