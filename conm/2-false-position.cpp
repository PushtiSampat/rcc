

 /* ===========================================================
 * File:      2-false-position.cpp
 * Copyright: 10-Feb-2020 by Ajinkya Rathod(ajinzrathod)
 * 
 * Content:   False Position Method
 * ========================================================== */

#include<iostream>
#include<math.h>
#include <iomanip>
#include <stdbool.h>
#include <conio.h>

#define EPSILON 0.000000005

using namespace std;

double f(double x)
{
	return ((x * x * x) - (9 * x) + 1);
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
	cout << setw(18) << f(a) << " |" << setw(15) << f(b) << " |" ; 
	cout << setw(20) <<   c  << " |" << setw(20) << f(c) << endl ;
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
	double a = 0.00, b = 1.00;
	bool sign_a, sign_b;

	while(1) {

		if(sign(f(a)) == sign(f(b))) {
			a += 1;
			b += 1;
		}
		else { break; }
	}

	cout << setw(10) << "a"    << " |"  << setw(10) << "b"     << " |" ; 
	cout << setw(18) << "f(a)" << " |"  << setw(15) << "f(b)"  << " |"; 
	cout << setw(20) << "c"    << " |"  << setw(20) << "f(c)"  ;

	cout << endl << endl;
	
	recursive(a, b);

	return 0;
}


 /* ===========================================================
 Output :
         a |         b |              f(a) |           f(b) |                   c |                f(c)

         0 |         1 |                 1 |             -7 |               0.125 |           -0.123047
         0 |     0.125 |                 1 |      -0.123047 |            0.111304 |        -0.000360219
         0 |  0.111304 |                 1 |   -0.000360219 |            0.111264 |       -9.92526e-007
         0 |  0.111264 |                 1 |  -9.92526e-007 |            0.111264 |       -2.73425e-009
         0 |  0.111264 |                 1 |  -2.73425e-009 |            0.111264 |       -7.53246e-012
         0 |  0.111264 |                 1 |  -7.53246e-012 |            0.111264 |       -2.07464e-014
         0 |  0.111264 |                 1 |  -2.07464e-014 |            0.111264 |        -9.8554e-017
         0 |  0.111264 |                 1 |   -9.8554e-017 |            0.111264 |        2.58582e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
  0.111264 |  0.111264 |      2.58582e-017 |   -9.8554e-017 |            0.111264 |        -9.8554e-017
 
 * ========================================================== */


