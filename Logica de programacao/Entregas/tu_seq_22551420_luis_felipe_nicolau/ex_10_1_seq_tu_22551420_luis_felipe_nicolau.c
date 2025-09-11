/*
 * Descrição: Calcula a raiz de uma equação do 1º grau (ax + b = 0) a partir dos coeficientes fornecidos pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float a, b, raiz;

    printf("Digite o coeficiente a: ");
    scanf("%f", &a);
    printf("Digite o coeficiente b: ");
    scanf("%f", &b);

    raiz = -b / a;

    printf("A raiz da equação %.2fx + %.2f = 0 é: %.2f\n", a, b, raiz);
}
