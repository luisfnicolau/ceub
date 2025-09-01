/*
 * Descrição: Calcula o volume de uma esfera a partir do raio fornecido pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>
#include <math.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float raio, volume;

    printf("Digite o valor do raio da esfera: ");
    scanf("%f", &raio);

    volume = (4 / 3) * M_PI * pow(raio, 3);

    printf("O volume da esfera é: %.2f\n", volume);
}
