/*
Autor: Luis Felipe Moraes Nicolau
Data: 03/10/2025
Imprime números de 1 até 10 e depois de 10 até 1
*/

#include <stdio.h>
#include <locale.h>
#define INT "%d" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	int contador = 1;
	
	printf("\nNúmeros de 1 até 10:");
	while (contador <= 10)
	{
		printf("\n%d", contador);
		contador++;
	}
	
	contador--;
	printf("\n\nNúmeros de 10 até 1:");
	while (contador >= 1)
	{
		printf("\n%d", contador);
		contador--;
	}
	
}
