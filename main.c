#include <stdio.h>
#include <math.h>

#define E 2.71828182845904523536
#define PI 3.14159265358979323846

double Quality(int index);
double Somatorio(int index);
void IQA();
void printResult(double finalValue);

//medias
double calculoOD(double OD);
double calculoCF(double CF);
double calculoPh(double pH);
double calculoDBO(double DBO);
double calculoTU(double Tu);
double calculoST(double ST);
double calculoVT(double VT);
double calculoNO3(double NO3);
double calculoPO4(double PO);

double pesos[9] = {0.15, 0.12, 0.1, 0.1, 0.1, 0.1, 0.08, 0.08, 0.17};

int main(void)
{
	//double pO = 0.17, pCF = 0.15, pPH = 0.12, pDBO = 0.1, pN = 0.1, pF = 0.1, pVT = 0.1, pT = 0.08, pRT = 0.08; //Pesos de cada parâmetro
	
	IQA();
}

void IQA() // Produtorio
{
	printf("Inicio do calculo de IQA\n");
	
	int i;
	double currIQA = 1;
	
	for(i = 0; i < 9; i++)
	{
		double pot = pow(Quality(i), Somatorio(i));
		
		currIQA *= pot;
		
		//printf("index - %d / currIQA = %lf\n", i, pot);
	}
	
	//currIQA *= 100;
	
	printResult(currIQA);
}

void printResult(double finalValue)
{
	if(finalValue <= 19)
	{
		printf("%lf - Pessima\n", finalValue);
	}
	else if (finalValue <= 36)
	{
		printf("%lf - Ruim\n", finalValue);
	}
	else if (finalValue <= 51)
	{
		printf("%lf - Regular\n", finalValue);
	}
	else if (finalValue <= 79)
	{
		printf("%lf - Boa\n", finalValue);
	}
	else
	{
		printf("%lf - Otima\n", finalValue);
	}
}

double Quality(int index)
{
	switch(index)
	{
		case 0:
			printf("Digite a concentracao media do Residuos totais:\n");
		break;
		case 1:
			printf("Digite a potencia do Coliformes fecais:\n");
		break;
		case 2:
			printf("Digite a concentracao media do pH:\n");
		break;
		case 3:
			printf("Digite a concentracao media do Demanda bioquimica de Oxigenio - DBO:\n");
		break;
		case 4:
			printf("Digite a concentracao media do Nitratos:\n");
		break;
		case 5:
			printf("Digite a concentracao media do Fosfatos:\n");
		break;
		case 6:
			printf("Digite a concentracao media do Variacao na Temperatura:\n");
		break;
		case 7:
			printf("Digite a concentracao media do Turbidez:\n");
		break;
		case 8:
			printf("Digite a concentracao media do Oxigenio dissolvido:\n");
		break;
	}
	
	double iValue = 0;
	scanf("%lf", &iValue);
	printf("Valor digitado: %lf\n", iValue);
	
	switch(index)
	{
		case 0:
			calculoST(iValue);
		break;
		case 1:
			calculoCF(iValue);
		break;
		case 2:
			calculoPh(iValue);
		break;
		case 3:
			calculoDBO(iValue);
		break;
		case 4:
			calculoNO3(iValue);
		break;
		case 5:
			calculoPO4(iValue);
		break;
		case 6:
			calculoVT(iValue);
		break;
		case 7:
			calculoTU(iValue);
		break;
		case 8:
			calculoOD(iValue);
		break;
	}
	
	return iValue;
}

double Somatorio(int index)
{
	int i;
	double finalValue = 0;
	
	for(i = 0; i <= index; i++)
	{
		finalValue += pesos[index];
	}
	
	finalValue = (finalValue > 1) ? 1 : finalValue;
	
	//printf("Somatorio index %d / %lf\n", index, finalValue);
	
	return finalValue;
}

double calculoOD(double OD) //oxigenio dissolvido
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
	
	return qs;
}

double calculoCF(double CF) // Coliformes fecais
{
	double qs = 0;
	
	if(pow(10,CF) <= pow(10, 5))
	{
		qs = 98.24034 - 34.7145 * (log10(pow(10,CF))) + 2.614267 * pow(log10(pow(10,CF)),2) + 0.107821 * pow(log10(pow(10,CF)),3);
	}
	else
		qs = 3.0;

	
	printf("%lf", qs);
	
	return qs;
}

double calculoPh(double pH) //ph
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
	
	return qs;
}

double calculoDBO(double DBO) // Demanda Bioquímica de Oxigênio
{
	double qs = 0;
	
	if(DBO <= 30)
		qs = 100.9571 - 10.7121 * DBO + 0.49544 * pow(DBO,2) - 0.011167 * pow(DBO,3) + 0.0001 * pow(DBO,4);
	else
		qs = 30.0;
	
	printf("%lf", qs);
	
	return qs;
}

double calculoVT(double VT)//temperatura
{
	double qs = 93; //clima br constante para o estudado
	
	printf("%lf", qs);
	return qs;
}

double calculoNO3(double NO3)// nitrogenio total
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
	
	return qs;
}

double calculoPO4(double PO) // fosfato
{
	double qs = 0;
	
	if(PO <= 10)
		qs = 79.7 * pow(PO + 0.821, -1.15);
	else if(PO > 10)
		qs = 5;
		
	printf("%lf", qs);
	
	return qs;
}

double calculoTU(double Tu)// turbidez
{
	double qs = 0;
	
	if(Tu <= 100)
		qs = 90.37 * pow(E, -0.0169 * Tu) - 15 * cos(0.0571 * (Tu - 30)) + 10.22 * pow(E, -0.231 * Tu) - 0.8;
	else
		qs = 5;
		
	printf("%lf", qs);
	return qs;
}

double calculoST(double ST)//solidos ou residuos total
{
	double qs = 0;
	
	if(ST <= 500)
		qs = 133.17 * pow(E, -0.0027 * ST) - 53.17 * pow(E,- 0.0141 * ST) + ((- 6.2 * pow(E, - 0.00462 * ST)) * sin(0.0146 * ST));
	else
		qs = 30;

		
	printf("%lf", qs);
	return qs;
}
