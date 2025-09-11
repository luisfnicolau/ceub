/*
 * Descrição: Exibe dois valores fornecidos pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
    setlocale(LC_ALL, "Portuguese");
    float val_1, val_2;
    printf("Digite o primeiro valor: ");
    scanf("%f", &val_1);
    printf("Digite o segundo valor: ");
    scanf("%f", &val_2);
    printf("A soma dos valores é: %.2f\n", val_1 + val_2);
}