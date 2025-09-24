/*
Autor: Luis Felipe Moraes Nicolau
Data: 24/09/2025
Exibe uma tabela com os primeiros 10 valores de temperatura, em graus e fehreinheit, a partir de 32 graus fahrenheit
*/

#include <stdio.h>
#include <locale.h>
#define FLOAT "%f" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	float far = 32, cel;
	printf("\nCONVERSÃO FAHREINHEIT - CELSIUS");
	printf("\nCELSIUS             FAHREINHEIT");
	while(far < 52)
	{
		cel = (5.0/9.0)*(far-32.0);
		printf("\n%.2f                    %.2f", cel, far);
		far++;
	}
}
