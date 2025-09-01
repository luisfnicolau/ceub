/*
 * Descrição: Calcula a área de um círculo a partir do raio fornecido pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>
#include <math.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float raio, area;

    printf("Digite o valor do raio do círculo: ");
    scanf("%f", &raio);

    area = M_PI * pow(raio, 2);

    printf("A área do círculo é: %.2f\n", area);
}
