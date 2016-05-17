#include <stdio.h>
#include <math.h>

double Quality(int index);
double Somatorio(int index);
void IQA();
void printResult(double finalValue);

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
	
	currIQA *= 100;
	
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
	printf("Entre um valor entre 0 - pior e 1 - melhor qualidade.\n");
	switch(index)
	{
		case 0:
			printf("Digite a concentracao media do Residuos totais:\n");
		break;
		case 1:
			printf("Digite a concentracao media do Coliformes fecais:\n");
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