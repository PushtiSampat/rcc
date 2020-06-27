

 /* ===========================================================
 * Content:   Fixed Point Method
 * ========================================================== */



#include<stdio.h>
#include<conio.h>
#include<math.h>
#define EPSILON 0.0000005

double g(double x)
{
	double sum;
	sum = (1 + cos(x)) / 3;
	return sum;
}

void fixed_point(double x)
{

	int i = 1, limit;
	double c;

	printf("Enter value of x: ");
	scanf("%lf",&x);
	
	printf("Enter Maximum iterations: ");
	scanf("%d",&limit);
	
	printf("no \t \tx \t \t\t g(x)");
	
	while(fabs(x-g(x)) > EPSILON && i <= limit) {
		printf("\n%d |\t\t%lf |\t\t%lf",i,x,g(x));
		x = g(x);
		i += 1;
	}
}


int main()
{
	double x = 0;

	fixed_point(x);
	
	return 0;
}



 /* ===========================================================
 Output :


	Enter value of x: 0
	Enter Maximum iterations: 15
	no              x                        g(x)
	1 |             0.000000 |              0.666667
	2 |             0.666667 |              0.595296
	3 |             0.595296 |              0.609328
	4 |             0.609328 |              0.606678
	5 |             0.606678 |              0.607182
	6 |             0.607182 |              0.607086
	7 |             0.607086 |              0.607105
	8 |             0.607105 |              0.607101
	9 |             0.607101 |              0.607102


 * ========================================================== */


