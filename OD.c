#include <stdio.h>
#include <math.h>

void calculoOD(double OD);

int main(void) {
	// your code goes here
	
	calculoOD(140);
	return 0;
}

void calculoOD(double OD)
{
	double qs;
	
	if(OD <= 100)
	{
		
	}
	else if(OD <= 140)
	{
		qs = - 0.00777142857142832 * pow(OD,2) + 1.27854285714278 * OD + 49.8817148572;

	}
	else
		qs = 47.0;
	
	printf("%lf", qs);
}