/*
Autor: Luis Felipe Moraes Nicolau
Data: 03/10/2025
Imprime todos os números de 1 até o número informado pelo usuário
*/

#include <stdio.h>
#include <locale.h>
#define INT "%d" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	int n, contador = 1;
	
	printf("\nDigite um número inteiro maior que 1: ");
	scanf(INT, &n);
	
	if (n > 1)
	{
		printf("\nNúmeros de 1 até %d:", n);
		while (contador <= n)
		{
			printf("\n%d", contador);
			contador++;
		}
	}
	else
	{
		printf("\nNúmero deve ser maior que 1!");
	}
	
}
