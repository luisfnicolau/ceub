/*
Autor: Luis Felipe Moraes Nicolau
Data: 03/10/2025
Implementa a tabuada de um número inteiro
*/

#include <stdio.h>
#include <locale.h>
#define INT "%d" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	int n, contador = 0;
	
	printf("\nDigite um número inteiro para a tabuada: ");
	scanf(INT, &n);
	
	printf("\nTabuada do %d", n);
	
	while (contador <= 10)
	{
		printf("\n%d x %d = %d", n, contador, n * contador);
		contador++;
	}
	
}
