#include <stdio.h>
#include <math.h>

double calculoPh(double pH);

int main(void) {
	// your code goes here
	calculoPh(7);
	
	return 0;
}

double calculoPh(double pH)
{
	double qs = 0;
	
	if(pH <= 2)
		qs = 2.0;
	else if(pH <= 6.9)
		qs =  -37.1085 + 41.91277 * pH - 15.7043 * pow(pH, 2) + 2.417486 * pow(pH, 3) - 0.091252 * pow(pH, 4);
	else if(pH <= 7.1)
		qs = -4.69365 - (21.4593 * pH) - (68.4561 * pow(pH,2)) + (21.638886 * pow(pH,3)) - (1.59165 * pow(pH,4));
	else if(pH <= 12)
		qs =  -7698.19 + 3262.031 * pH - 499.494 * pow(pH,2) + 33.1551 * pow(pH,3) - 0.810613 * pow(pH,4);
	else
		qs = 3.0;
	
	printf("%lf", qs);
}
