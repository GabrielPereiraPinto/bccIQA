#include <stdio.h>
#include <math.h>

double calculoDBO(double DBO);

int main(void) {
	// your code goes here
	calculoDBO(15);
	
	return 0;
}

double calculoDBO(double DBO)
{
	double qs = 0;
	
	if(DBO <= 30)
		qs = 100.9571 - 10.7121 * DBO + 0.49544 * pow(DBO,2) - 0.011167 * pow(DBO,3) + 0.0001 * pow(DBO,4);
	else
		qs = 30.0;
	
	printf("%lf", qs);
}
