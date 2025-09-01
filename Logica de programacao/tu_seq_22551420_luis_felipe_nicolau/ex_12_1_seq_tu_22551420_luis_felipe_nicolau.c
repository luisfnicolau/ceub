/*
 * Descrição: Lê dois valores reais e mostra o resultado da adição e subtração desses valores.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float valor1, valor2, adicao, subtracao;

    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);
    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);

    adicao = valor1 + valor2;
    subtracao = valor1 - valor2;

    printf("\nResultados:\n");
    printf("Adição: %.2f + %.2f = %.2f\n", valor1, valor2, adicao);
    printf("Subtração: %.2f - %.2f = %.2f\n", valor1, valor2, subtracao);
}
