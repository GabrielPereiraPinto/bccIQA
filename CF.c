#include <stdio.h>
#include <math.h>

double calculoCF(double CF);

int main(void) {
	// your code goes here
	calculoCF(2);
	
	return 0;
}

double calculoCF(double CF)
{
	double qs = 0;
	
	if(pow(10,CF) <= pow(10, 5))
	{
		qs = 98.24034 - 34.7145 * (log10(pow(10,CF))) + 2.614267 * pow(log10(pow(10,CF)),2) + 0.107821 * pow(log10(pow(10,CF)),3);
	}
	else
		qs = 3.0;

	
	printf("%lf", qs);
}
