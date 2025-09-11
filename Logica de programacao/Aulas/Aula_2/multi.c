#include <stdio.h>

int main(void)
{

    float valor_1, valor_2; // = float valor_1; float valor_2;

    printf("\nInsira o primeiro valor: ");
    scanf("%f", &valor_1);

    printf("Insira o primeiro valor: \n");
    scanf("%f", &valor_2);

    float multiplicacao = valor_1 * valor_2;

    printf("O valor de %.1f vezes %.2f é: %.2f\n", valor_1, valor_2, multiplicacao);
}

// tipo nome_da_variavel = valor_inicial

// !, @, #, $, %, ^, &, *, (, ), +, =, -, /, \, |, <, >, ?, `, ~, ,, ., ;, :, ', "
// Não pode começar com numeros

// Operadores matemático: -, +, *, /

// stdio.h -> standart input output