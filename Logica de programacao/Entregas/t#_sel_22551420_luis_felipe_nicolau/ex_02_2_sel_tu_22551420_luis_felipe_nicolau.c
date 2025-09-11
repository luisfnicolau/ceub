/*
 * Descrição: Exibe qual o valor maior dentro dois valores.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */
 
#include <stdio.h>
#include <locale.h>

void main(void) {
	setlocale(LC_ALL, "Portuguese");
	
	float valor_1, valor_2;
	
	printf("\nDigite o primeiro valor: ");
	
	scanf("%f", &valor_1);

	printf("\nDigite o segundo valor: ");
	
	scanf("%f", &valor_2);
	
	if(valor_1 > valor_2) {
		printf("\nO primeiro valor � maior", valor_1);
		printf("\nMaior valor: %f", valor_1);
		printf("\nMenor valor: %f", valor_2);
	} else if (valor_1 < valor_2) {
		printf("\nO segundo valor � maior: %f", valor_2);
		printf("\nMaior valor: %f", valor_2);
		printf("\nMenor valor: %f", valor_1);
	} else {
		printf("\nOs valores s�o iguais");
		printf("\nValor: %f", valor_1);
	}
}
