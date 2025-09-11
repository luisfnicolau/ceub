/*
 * Descrição: Converte uma medida em pés para metros (1 pé = 0.3048m).
 * Autor: Luis Felipe Nicolau
 * Data: 01/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void)
{
    setlocale(LC_ALL, "portuguese");
    float pes, metros;

    printf("Digite o valor em pés: ");
    scanf("%f", &pes);

    metros = pes * 0.3048;

    printf("%.2f pés equivalem a %.2f metros\n", pes, metros);
}
