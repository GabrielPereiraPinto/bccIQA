#include <stdio.h>
#include <math.h>

#define E 2.71828182845904523536
#define PI 3.14159265358979323846

void calculoOD(double OD);

int main(void) {
	// your code goes here
	
	calculoOD(40);
	return 0;
}

void calculoOD(double OD)
{
	double qs;
	
	if(OD <= 100)
	{
		double y[5];
		
		y[0] = 0.01396 * OD + 0.0873;
		y[1] = (PI / 56) * (OD - 27.0);
		y[2] = (PI / 85) - (OD - 15);
		y[3] = (OD - 65) / 10;
		y[4] = (65 - OD) / 10;
		
		qs = 100 * pow(sin(y[0]),2) - ((2.5 * sin (y[1]) - 0.018 * OD + 6.86) * sin (y[2])) + (12 / (pow(E, y[3]) + pow(E, y[4])));
	}
	else if(OD <= 140)
	{
		qs = (-0.00777142857142832 * pow(OD,2)) + (1.27854285714278 * OD) + 49.8817148572;

	}
	else
		qs = 47.0;
	
	printf("%lf", qs);
}
