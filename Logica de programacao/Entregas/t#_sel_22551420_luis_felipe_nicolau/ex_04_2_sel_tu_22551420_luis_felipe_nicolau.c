/*
 * Descri√ß√£o: Calcula o peso ideial de uma pessoa, baseado na sua altura e sexo.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void) {
    setlocale(LC_ALL, "Portuguese");

    char sex;
    float altura, pesoIdeal;
    printf("\nO peso a ser calculado È de um homem ou de uma mulher? (Homem: m, Mulher: f): ");
    scanf("%c", &sex);

    if (sex != 'm' && sex != 'f'){
        printf("GÍnero inv·lido: %c", sex);
    }
    printf("\nEntre com a altura(m): ");
    scanf("%f", &altura);

    if (sex == 'm') {
        pesoIdeal = (72.7 * altura) - 58;
    } else {
        pesoIdeal = (62.1 * altura) - 44.7;
    }

    printf("\nO peso ideial È: %.2f", pesoIdeal);
}
