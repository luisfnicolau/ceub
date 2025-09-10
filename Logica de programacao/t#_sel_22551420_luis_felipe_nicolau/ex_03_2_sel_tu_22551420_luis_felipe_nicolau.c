#include <stdio.h>
#include <locale.h>

void main(void) {
	setlocale(LC_ALL, "Portuguese");
	float valor;
	
	printf("\nDigite o valor: ");
	
	scanf("%f", &valor);
	
	printf("\nValor digitado: %.2f", valor);
	if (valor > 0) {
		printf("\nNúmero positivo");
		printf("\nDobro do valor: %.2f", valor * 2);
	} else if (valor < 0) {
		printf("\nNúmero negativo");
		printf("\nTriplo do valor: %.2f", valor * 3);
	} else {
		printf("\nNúmero nulo");
		printf("\nValor da variável: %.2f", valor);
	}
}
