/*
 * Descrição: Verifica se um numero é par ou impar.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    int valor;
    
    printf("Entre com o número: ", valor);
    
    scanf("%i", &valor);
    
    if (valor % 2 == 0) {
    	printf("Este é um número par");
	} else {
		printf("Este é um número impar");
	}
}
