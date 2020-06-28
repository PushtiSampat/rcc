

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
	return x * exp(x) - 1;
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

  1         0 |         1 |        -1 |   1.71828 |       0.5 | -0.175639
  2  0.500000 |  1.000000 | -0.175639 |  1.718282 |  0.750000 |  0.587750
  3  0.500000 |  0.750000 | -0.175639 |  0.587750 |  0.625000 |  0.167654
  4  0.500000 |  0.625000 | -0.175639 |  0.167654 |  0.562500 | -0.012782
  5  0.562500 |  0.625000 | -0.012782 |  0.167654 |  0.593750 |  0.075142
  6  0.562500 |  0.593750 | -0.012782 |  0.075142 |  0.578125 |  0.030619
  7  0.562500 |  0.578125 | -0.012782 |  0.030619 |  0.570312 |  0.008780
  8  0.562500 |  0.570312 | -0.012782 |  0.008780 |  0.566406 | -0.002035
  9  0.566406 |  0.570312 | -0.002035 |  0.008780 |  0.568359 |  0.003364
 10  0.566406 |  0.568359 | -0.002035 |  0.003364 |  0.567383 |  0.000662
 11  0.566406 |  0.567383 | -0.002035 |  0.000662 |  0.566895 | -0.000687
 12  0.566895 |  0.567383 | -0.000687 |  0.000662 |  0.567139 | -0.000013
 13  0.567139 |  0.567383 | -0.000013 |  0.000662 |  0.567261 |  0.000325
 14  0.567139 |  0.567261 | -0.000013 |  0.000325 |  0.567200 |  0.000156
 15  0.567139 |  0.567200 | -0.000013 |  0.000156 |  0.567169 |  0.000072
 16  0.567139 |  0.567169 | -0.000013 |  0.000072 |  0.567154 |  0.000029
 17  0.567139 |  0.567154 | -0.000013 |  0.000029 |  0.567146 |  0.000008
 18  0.567139 |  0.567146 | -0.000013 |  0.000008 |  0.567142 | -0.000002

 * ========================================================== */


