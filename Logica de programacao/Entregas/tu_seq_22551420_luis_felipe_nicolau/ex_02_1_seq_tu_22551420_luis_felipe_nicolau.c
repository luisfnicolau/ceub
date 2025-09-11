/*
 * Descrição: Calcula a soma de dois valores.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
	setlocale(LC_ALL, "Portuguese");
	float v1, v2, soma;
	printf("Valor 1: ");
	scanf("%f", &v1);
	printf("Valor 2: ");
	scanf("%f", &v2);
	soma = v1 + v2;
	printf("\n A soma dos valores é: %f\n", soma);
	printf("\n A substração dos valores é: %f\n", v1 - v2);
	printf("\n A multiplicação dos valores é: %f\n", v1 * v2);
}
