/*
 * Descrição: Solicita 3 números em ponto flutuante e calcula a média aritmética desses números.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float num1, num2, num3, media;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);
    printf("Digite o segundo número: ");
    scanf("%f", &num2);
    printf("Digite o terceiro número: ");
    scanf("%f", &num3);

    media = (num1 + num2 + num3) / 3;

    printf("A média aritmética dos três números é: %.2f\n", media);
}
