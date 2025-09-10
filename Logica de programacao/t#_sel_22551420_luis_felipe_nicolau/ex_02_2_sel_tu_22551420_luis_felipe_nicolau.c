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
		printf("\nO primeiro valor é maior", valor_1);
		printf("\nMaior valor: %f", valor_1);
		printf("\nMenor valor: %f", valor_2);
	} else if (valor_1 < valor_2) {
		printf("\nO segundo valor é maior: %f", valor_2);
		printf("\nMaior valor: %f", valor_2);
		printf("\nMenor valor: %f", valor_1);
	} else {
		printf("\nOs valores são iguais");
		printf("\nValor: %f", valor_1);
	}
}
