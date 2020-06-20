 /* ===========================================================
 * File:      1-bisection.cpp
 * Copyright: 10-Feb-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:   Bisection Method
 * ========================================================== */

#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdbool.h>
// #include <conio.h>
#include <cassert>

#define EPSILON 0.000005

using namespace std;

double f(double x)
{
	return ((x * x * x) - (9 * x) + 1);
	// return ((3 * x) - (cos(x)) - 1);
	// return (x * x * x) + x - 1;
	// return x * (log10(x)) - 1.2;
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
		cout << endl << " *** Neither +ve nor -ve. Returning value 0 *** " << endl;
		return 0;
	}
}

void displayData(double a, double b, double c) 
{
	static int count = 0;
	cout << setw(04) << ++count;
	cout << setw(10) <<   a  << " |" << setw(10) <<   b  << " |" ;
	cout << setw(18) << setprecision(4) << f(a) << " |" << setw(15) << f(b) << " |" ; 
	cout << setw(20) <<   c  << " |";
	cout << setw(20) << setprecision(5) << fixed << f(c) << endl;
}

void recursive(double a, double b)
{
	double c  = (a + b) / 2; 
	// double c  = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));
	static int count = 0;

	displayData(a, b, c);

	
	// Accurate upto 6 decimal places 
	
	float nearest = fabs(roundf(f(c) * 1000000) / 1000000);
	if (EPSILON > nearest) { return; }
	
	// Accurate upto 6 decimal places Ends

	
	if((f(c) * f(b)) < 0) { // if negative
		recursive(c, b);
	}
	else { // if positive
		recursive(a, c);
	}
}

int main()
{
	double a = 0.00, b = 1.00;
	bool sign_a, sign_b;
	
	while(1) {

		if(sign(f(a)) == sign(f(b))) {
			a += 1;
			b += 1;
		}
		else { break; }
	}
	cout << setw(04) << "No.";
	cout << setw(10) << "a"    << " |"  << setw(10) << "b"     << " |" ; 
	cout << setw(18) << "f(a)" << " |"  << setw(15) << "f(b)"  << " |"; 
	cout << setw(20) << "c"    << " |"  << setw(20) << "f(c)"  ;

	cout << endl << endl;
	
	recursive(a, b);

	return 0;
}

 /* ===========================================================
 Output :


 
 * ========================================================== */