/*
 * Descri��o: Verifica se um numero � par ou impar.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    int valor;
    
    printf("Entre com o n�mero: ", valor);
    
    scanf("%i", &valor);
    
    if (valor % 2 == 0) {
    	printf("Este � um n�mero par");
	} else {
		printf("Este � um n�mero impar");
	}
}
