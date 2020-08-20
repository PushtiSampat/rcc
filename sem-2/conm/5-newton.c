
 /* ===========================================================
 * Content:   Newton Rahpson Method
 * ========================================================== */



#include<stdio.h>
#include<math.h>
#define EPSILON 0.0000005


double function5(double x,double y)
{
	return (x * x) - y;
}


double dfunction5(double x)
{
	return 2 * x;
}


void newton_rafson(double x)
{
	double c, y;
	int i = 1, limit, flag = 0;
	
	printf("Enter number to find its square root: ");
	scanf("%lf",&y);

	printf("Enter x: ");
	scanf("%lf",&x);

	printf("Enter Max iter: ");
	scanf("%d",&limit);

	c = x - (function5(x, y) / dfunction5(x));

	printf("\n\nno\txn\t\tf(xn)\t\tf'(xn)\t\txn+1\t\tf(xn+1)");

	printf("\n\n%d |\t%lf |\t%lf |\t%lf |\t%lf |\t%lf",i,x,function5(x,y),dfunction5(x),c,function5(c,y));

	while(fabs(function5(c,y)) >= EPSILON && i<limit) {
		i++;
		x = c;
		if(fabs(dfunction5(x)) < 0.00001) {
			printf("\nDivide by zero Error encountered!!!");
			flag = 1;
			break;
		}

		c=x-(function5(x,y)/dfunction5(x));
		
		printf("\n%d |\t%lf |\t%lf |\t%lf |\t%lf |\t%lf",i,x,function5(x,y),dfunction5(x),c,function5(c,y));
	}
	if(flag != 1)
		printf("\n\nRoot =%lf",c);
}


int main()
{
	double x=0;

	newton_rafson(x);
	
	return 0;
}



 /* ===========================================================
 Output :

	Enter number to find its square root: 2
	Enter x: 5
	Enter Max iter: 7


	no      xn              f(xn)           f'(xn)          xn+1            f(xn+1)

	1 |     5.000000 |      23.000000 |     10.000000 |     2.700000 |      5.290000
	2 |     2.700000 |      5.290000 |      5.400000 |      1.720370 |      0.959674
	3 |     1.720370 |      0.959674 |      3.440741 |      1.441455 |      0.077794
	4 |     1.441455 |      0.077794 |      2.882911 |      1.414471 |      0.000728
	5 |     1.414471 |      0.000728 |      2.828942 |      1.414214 |      0.000000

	Root =1.414214


 * ========================================================== */


