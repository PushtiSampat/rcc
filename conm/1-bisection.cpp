

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

  1         0 |         1 |         1 |        -7 |       0.5 | -3.375000
  2  0.000000 |  0.500000 |  1.000000 | -3.375000 |  0.250000 | -1.234375
  3  0.000000 |  0.250000 |  1.000000 | -1.234375 |  0.125000 | -0.123047
  4  0.000000 |  0.125000 |  1.000000 | -0.123047 |  0.062500 |  0.437744
  5  0.062500 |  0.125000 |  0.437744 | -0.123047 |  0.093750 |  0.157074
  6  0.093750 |  0.125000 |  0.157074 | -0.123047 |  0.109375 |  0.016933
  7  0.109375 |  0.125000 |  0.016933 | -0.123047 |  0.117188 | -0.053078
  8  0.109375 |  0.117188 |  0.016933 | -0.053078 |  0.113281 | -0.018078
  9  0.109375 |  0.113281 |  0.016933 | -0.018078 |  0.111328 | -0.000573
 10  0.109375 |  0.111328 |  0.016933 | -0.000573 |  0.110352 |  0.008180
 11  0.110352 |  0.111328 |  0.008180 | -0.000573 |  0.110840 |  0.003803
 12  0.110840 |  0.111328 |  0.003803 | -0.000573 |  0.111084 |  0.001615
 13  0.111084 |  0.111328 |  0.001615 | -0.000573 |  0.111206 |  0.000521
 14  0.111206 |  0.111328 |  0.000521 | -0.000573 |  0.111267 | -0.000026
 15  0.111206 |  0.111267 |  0.000521 | -0.000026 |  0.111237 |  0.000247
 16  0.111237 |  0.111267 |  0.000247 | -0.000026 |  0.111252 |  0.000110
 17  0.111252 |  0.111267 |  0.000110 | -0.000026 |  0.111259 |  0.000042
 18  0.111259 |  0.111267 |  0.000042 | -0.000026 |  0.111263 |  0.000008
 19  0.111263 |  0.111267 |  0.000008 | -0.000026 |  0.111265 | -0.000009
 20  0.111263 |  0.111265 |  0.000008 | -0.000009 |  0.111264 | -0.000001

 * ========================================================== */


