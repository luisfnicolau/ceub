/*
 * Descrição: Calcula a área de um triângulo.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
	setlocale(LC_ALL, "portuguese");
	float base, altura, area;

	printf("Digite o valor da base do triângulo: ");
	scanf("%f", &base);
	printf("Digite o valor da altura do triângulo: ");
	scanf("%f", &altura);
	area = (base * altura) / 2;
	printf("A área do triângulo é: %.3f\n", area);
	printf("A base do triângulo é: %.3f\n", base);
	printf("A altura do triângulo é: %.3f\n", altura);
}
