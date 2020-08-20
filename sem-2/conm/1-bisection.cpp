

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
	return (x * x * x) - (x) - 1;
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
	cout << setw(03) << ++count;
	cout << setw(10) <<   a  << " |" << setw(10) <<   b  << " |" ;
	cout << setw(10) << setprecision(6) << f(a) << " |" << setw(10) << f(b) << " |" ; 
	cout << setw(10) <<   c  << " |";
	cout << setw(10) << setprecision(6) << fixed << f(c) << endl;
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

 No.        a |         b |      f(a) |      f(b) |         c |      f(c)

  1         1 |         2 |        -1 |         5 |       1.5 |  0.875000
  2  1.000000 |  1.500000 | -1.000000 |  0.875000 |  1.250000 | -0.296875
  3  1.250000 |  1.500000 | -0.296875 |  0.875000 |  1.375000 |  0.224609
  4  1.250000 |  1.375000 | -0.296875 |  0.224609 |  1.312500 | -0.051514
  5  1.312500 |  1.375000 | -0.051514 |  0.224609 |  1.343750 |  0.082611
  6  1.312500 |  1.343750 | -0.051514 |  0.082611 |  1.328125 |  0.014576
  7  1.312500 |  1.328125 | -0.051514 |  0.014576 |  1.320312 | -0.018711
  8  1.320312 |  1.328125 | -0.018711 |  0.014576 |  1.324219 | -0.002128
  9  1.324219 |  1.328125 | -0.002128 |  0.014576 |  1.326172 |  0.006209
 10  1.324219 |  1.326172 | -0.002128 |  0.006209 |  1.325195 |  0.002037
 11  1.324219 |  1.325195 | -0.002128 |  0.002037 |  1.324707 | -0.000047
 12  1.324707 |  1.325195 | -0.000047 |  0.002037 |  1.324951 |  0.000995
 13  1.324707 |  1.324951 | -0.000047 |  0.000995 |  1.324829 |  0.000474
 14  1.324707 |  1.324829 | -0.000047 |  0.000474 |  1.324768 |  0.000214
 15  1.324707 |  1.324768 | -0.000047 |  0.000214 |  1.324738 |  0.000084
 16  1.324707 |  1.324738 | -0.000047 |  0.000084 |  1.324722 |  0.000018
 17  1.324707 |  1.324722 | -0.000047 |  0.000018 |  1.324715 | -0.000014
 18  1.324715 |  1.324722 | -0.000014 |  0.000018 |  1.324718 |  0.000002
 * ========================================================== */


