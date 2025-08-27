#include <stdio.h>
#include <locale.h>

void main(void) {
	setlocale(LC_ALL, "portuguese");
	float base, altura, area;
	printf("\nDigite o valor da base: ");
	scanf("%f", &base);
	printf("\nDigite o valor da altura: ");
	scanf("%f", &altura);
	area = (base * altura) / 2;
	printf("\nO triangulo de base %.2f, altura %.2f tem a área de %.2f", base, altura, area);
}
