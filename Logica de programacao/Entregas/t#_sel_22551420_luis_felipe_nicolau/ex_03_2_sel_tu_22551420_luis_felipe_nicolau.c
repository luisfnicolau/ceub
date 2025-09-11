/*
 * Descrição: Exibe se um dado numero é positivo, negativo ou nulo.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void) {
	setlocale(LC_ALL, "Portuguese");
	float valor;
	
	printf("\nDigite o valor: ");
	
	scanf("%f", &valor);
	
	printf("\nValor digitado: %.2f", valor);
	if (valor > 0) {
		printf("\nN�mero positivo");
		printf("\nDobro do valor: %.2f", valor * 2);
	} else if (valor < 0) {
		printf("\nN�mero negativo");
		printf("\nTriplo do valor: %.2f", valor * 3);
	} else {
		printf("\nN�mero nulo");
		printf("\nValor da vari�vel: %.2f", valor);
	}
}
