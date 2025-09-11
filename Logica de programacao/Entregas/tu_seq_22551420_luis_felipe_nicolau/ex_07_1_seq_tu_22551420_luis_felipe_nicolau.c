/*
 * Descrição: Calcula o comprimento de uma circunferência a partir do raio fornecido pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>
#include <math.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float raio, comprimento;

    printf("Digite o valor do raio da circunferência: ");
    scanf("%f", &raio);

    comprimento = 2 * M_PI * raio;

    printf("O comprimento da circunferência é: %.2f\n", comprimento);
}
