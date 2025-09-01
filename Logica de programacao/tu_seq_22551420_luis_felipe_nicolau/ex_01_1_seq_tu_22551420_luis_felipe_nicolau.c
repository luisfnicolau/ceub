/*
 * Descrição: Exibe dois valores fornecidos pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>

void main(void)
{
    float val_1, val_2;
    printf("Digite o primeiro valor: ");
    scanf("%f", &val_1);
    printf("Digite o segundo valor: ");
    scanf("%f", &val_2);
    printf("Os valores digitados foram: %.2f e %.2f\n", val_1, val_2);
}