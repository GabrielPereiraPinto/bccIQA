#include <stdio.h>
#include <math.h>

double calculoNO3(double NO3);

int main(void) {
	// your code goes here
	calculoNO3(0);
	
	return 0;
}

double calculoNO3(double NO3)
{
	double qs = 0;
	
	if(NO3 <= 10)
		qs = -5.1 * NO3 + 100.17;
	else if(NO3 <= 60)
		qs = -22.853 * log(NO3) + 101.18;
	else if(NO3 <= 90)
		qs = pow(10, 9) * pow(NO3, -5.1161);
	else
		qs = 1.0;
	
	printf("%lf", qs);
}
