/*
 * Descrição: Troca o conteúdo de duas variáveis inteiras fornecidas pelo usuário.
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    int valor1, valor2, auxVar;

    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &valor1);
    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &valor2);

    auxVar = valor1;
    valor1 = valor2;
    valor2 = auxVar;

    printf("Primeiro valor: %d\n", valor1);
    printf("Segundo valor: %d\n", valor2);
}
