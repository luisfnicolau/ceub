/*
Autor: Luis Felipe Moraes Nicolau
Data: 03/10/2025
Imprime a soma de todos os valores positivos digitados até que seja digitado um número negativo
*/

#include <stdio.h>
#include <locale.h>
#define FLOAT "%f" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	float numero, soma = 0;
	
	do
	{
		printf("\nDigite um número positivo (ou negativo para sair): ");
		scanf(FLOAT, &numero);
		
		if (numero >= 0)
		{
			soma += numero;
		}
	}
	while (numero >= 0);
	
	printf("\nSoma dos valores positivos: %.2f", soma);
	
}
