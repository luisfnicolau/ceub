/*
 * Descrição: Calcula a área lateral de um cilindro a partir do raio e altura fornecidos pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>
#include <math.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float raio, altura, area_lateral;

    printf("Digite o valor do raio do cilindro: ");
    scanf("%f", &raio);
    printf("Digite a altura do cilindro: ");
    scanf("%f", &altura);

    area_lateral = 2 * M_PI * raio * altura;

    printf("A área lateral do cilindro é: %.2f\n", area_lateral);
}
