#include <stdio.h>
#include <math.h>

#define E 2.71828182845904523536

double calculoTU(double Tu);
double calculoST(double ST);
double calculoVT(double VT);

int main(void) {
	// your code goes here
	
	calculoST(300);
	return 0;
}

double calculoTU(double Tu)
{
	double qs = 0;
	
	if(Tu <= 100)
		qs = 90.37 * pow(E, -0.0169 * Tu) - 15 * cos(0.0571 * (Tu - 30)) + 10.22 * pow(E, -0.231 * Tu) - 0.8;
	else
		qs = 5;
		
	printf("%lf", qs);
	return qs;
}

double calculoST(double ST)
{
	double qs = 0;
	
	if(ST <= 500)
		qs = 133.17 * pow(E, -0.0027 * ST) - 53.17 * pow(E,- 0.0141 * ST) + ((- 6.2 * pow(E, - 0.00462 * ST)) * sin(0.0146 * ST));
	else
		qs = 30;

		
	printf("%lf", qs);
	return qs;
}

double calculoVT(double VT)
{
	double qs = 93; //clima br constante para o estudado
	
	printf("%lf", qs);
	return qs;
}
