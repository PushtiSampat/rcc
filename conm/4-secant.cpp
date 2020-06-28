

 /* ===========================================================
 * Content:   Secant Method
 * ========================================================== */


#include<iostream>
#include<math.h>
#include <iomanip>

#define EPSILON 0.000000005

using namespace std;

double f(double x)
{
	return (3 * x) - cos(x) - 1;
}

bool sign(double value)
{
	if(f(value) < 0) {
		return 0; // value is less than 0
	}
	else if(f(value) > 0) {
		return 1; // value is greater than 0
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
	double c;
	bool sign_c;
	static int count = 1;

	a = b;
	b = c; 

	displayData(a, b, c);

	// if(f(c) > 0.000005) { return; }
	if(count++ > 15) { return; } 

// these below lines might not come, coz secant method does not care if sign is +ve or -ve
	// sign_c = sign(c);

	// if(sign_c) {
	// 	recursive(c, b);
	// }
	// else {
	// 	recursive(a, c);
	// }
}

int main()
{
	double a = 2.00;
	double b = 3.00;
	
	bool sign_a = true;
	bool sign_b = true;

	sign_a = sign(a);

	while(1) {
		sign_b = sign(b);

		if(sign_a == sign_b) {
			a += 1;
			b += 1;
		}
		else {
			break;
		}
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

       a             b         f(a)         f(b)            c          f(c)

2.000000 |    3.000000 |  -0.597940 |   0.231364 |   2.721014 |   -0.017091 |
2.721014 |    3.000000 |  -0.017091 |   0.231364 |   2.740206 |   -0.000384 |
2.740206 |    3.000000 |  -0.000384 |   0.231364 |   2.740636 |   -0.000009 |
2.740636 |    3.000000 |  -0.000009 |   0.231364 |   2.740646 |   -0.000000 |

 * ========================================================== */


