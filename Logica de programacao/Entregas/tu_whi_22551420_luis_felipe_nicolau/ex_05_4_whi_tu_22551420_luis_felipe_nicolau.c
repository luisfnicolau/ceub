/*
Autor: Luis Felipe Moraes Nicolau
Data: 03/10/2025
Lê vários números digitados pelo usuário até que seja digitado -1
*/

#include <stdio.h>
#include <locale.h>
#define FLOAT "%f" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	float numero, soma = 0;
	int contador = 0;
	
	printf("\nDigite o número (digite -1 para sair): ");
	scanf(FLOAT, &numero);
	
	while (numero != -1)
	{
		contador++;
		soma += numero;
		printf("\nDigite outro número (digite -1 para sair): ");
		scanf(FLOAT, &numero);
	}
	
	printf("\nQuantidade de números: %d", contador);
	printf("\nSoma dos valores: %.2f", soma);
	
}
