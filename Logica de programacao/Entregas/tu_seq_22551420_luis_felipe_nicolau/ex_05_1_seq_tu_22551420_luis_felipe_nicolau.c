/*
 * Descrição: Converte um valor em graus Fahrenheit para Celsius.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float fahrenheit, celsius;
    printf("Digite a temperatura em graus Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) / 1.8;
    printf("A temperatura em graus Celsius é: %.2f\n", celsius);
}