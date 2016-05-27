#include <stdio.h>
#include <math.h>

double calculoPO4(double PO);

int main(void) {
	// your code goes here
	
	calculoPO4(4);
	return 0;
}

double calculoPO4(double PO)
{
	double qs = 0;
	
	if(PO <= 10)
		qs = 79.7 * pow(PO + 0.821, -1.15);
	else if(PO > 10)
		qs = 10;
		
	printf("%lf", qs);
	return qs;
}
