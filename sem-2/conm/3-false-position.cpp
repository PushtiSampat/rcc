

 /* ===========================================================
 * File:      3-false-position.cpp
 * Copyright: 10-Feb-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:   False Position Method
 * ========================================================== */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdbool.h>
#include <conio.h>

#define EPSILON 0.000000005

using namespace std;

double f(double x)
{
	return (x * (log10(x)) - 1.2);
}

bool sign(double value)
{
	if(value < 0) {
		return 0; // value is less than 0
	}
	else if(value > 0) {
		return 1; // value is greater than 0
	}

	else {
		cout << "Neither +ve nor -ve. Returning value 0";
		getch();
		exit(1);
	}
}

void displayData(double a, double b, double c) 
{
	cout << setw(10) <<   a  << " |" << setw(10) <<   b  << " |" ;
	cout << setw(10) << f(a) << " |" << setw(15) << f(b) << " |" ; 
	cout << setw(10) <<   c  << " |" << setw(15) << f(c) << endl ;
}

void recursive(double a, double b)
{
	double c  = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));  
	static int count = 0;

	displayData(a, b, c);

	// if(f(c) > 0.000005) { return; }
	if(count++ > 15) { return; } 

	if(sign(f(c))) { // if sign_c is positive
		recursive(c, b);
	}
	else { // if sign_c is negative
		recursive(a, c);
	}

}

int main()
{
	double a = 2.00, b = 3.00;
	bool sign_a, sign_b;

	while(1) {

		if(sign(f(a)) == sign(f(b))) {
			a += 1;
			b += 1;
		}
		else { break; }
	}

	cout << setw(10) << "a"    << " |"  << setw(10) << "b"     << " |" ; 
	cout << setw(10) << "f(a)" << " |"  << setw(10) << "f(b)"  << " |"; 
	cout << setw(10) << "c"    << " |"  << setw(10) << "f(c)"  ;

	cout << endl << endl;
	
	recursive(a, b);

	return 0;
}


 /* ===========================================================
 Output :
         a |         b |      f(a) |           f(b) |         c |           f(c)
         
         2 |         3 |  -0.59794 |       0.231364 |   2.72101 |     -0.0170911
         2 |   2.72101 |  -0.59794 |     -0.0170911 |   2.74223 |     0.00138143
   2.74223 |   2.72101 |0.00138143 |     -0.0170911 |   2.74064 |  -2.47288e-006
   2.74223 |   2.74064 |0.00138143 |  -2.47288e-006 |   2.74065 |  -3.55667e-010
   2.74223 |   2.74065 |0.00138143 |  -3.55667e-010 |   2.74065 |  -5.12287e-014
   2.74223 |   2.74065 |0.00138143 |  -5.12287e-014 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016
   2.74223 |   2.74065 |0.00138143 |  -1.55041e-016 |   2.74065 |  -1.55041e-016 
 * ========================================================== */


