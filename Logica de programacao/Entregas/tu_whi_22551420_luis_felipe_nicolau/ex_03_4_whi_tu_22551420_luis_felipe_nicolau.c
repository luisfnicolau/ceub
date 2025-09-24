/*
Autor: Luis Felipe Moraes Nicolau
Data: 24/09/2025
Exibe uma tabela com os valores de temperatura, em graus e fehreinheit.
*/

#include <stdio.h>
#include <locale.h>
#define FLOAT "%f" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	float far, cel, temp_in, temp_fin;
	
	printf("\nEntre com a temperatura inicial (F): ");
	scanf(FLOAT, &temp_in);
	printf("\nEntre com a temperatura final (F): ");
	scanf(FLOAT, &temp_fin);
	
	far = temp_in;
	
	printf("\nCONVERSÃO FAHREINHEIT - CELSIUS");
	printf("\nCELSIUS             FAHREINHEIT");
	while(far < temp_fin)
	{
		cel = (5.0/9.0)*(far-32.0);
		printf("\n%.2f                    %.2f", cel, far);
		far++;
	}
}
