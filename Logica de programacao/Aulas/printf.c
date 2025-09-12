#include <stdio.h>

int main(void)
{
    int inteiro = 10;
    float fracionario = 10.5;
    char caractere = 'A';
    char string[] = "Hello, World!";
    int decimal_com_sinal = -20;
    int num1, num2;

    printf("Inteiro: %d\n", inteiro);
    printf("Inteiro: %i\n", inteiro);
    printf("Fracionario: %f\n", fracionario);
    printf("Caractere: %c\n", caractere);
    printf("String: %s\n", string);

    // Usando %d - sempre decimal
    printf("Digite um número (apenas decimal): ");
    scanf("%d", &num1);
    printf("Você digitou: %d\n", num1);

    // Usando %i - detecta base automaticamente
    printf("Digite um número (qualquer base): ");
    scanf("%i", &num2);
    printf("Você digitou: %d\n", num2);

    return 0;
}

/*  %s: imprimie uma string
    %i: imprimie um inteiro
    %d: imprimie um inteiro na base decimal
    %c: imprimie um caracter
    %f: imprimie um float/double

    Inteiros:
    %d - Inteiro decimal com sinal (signed)
    %i - Inteiro decimal com sinal (signed), detecta a base automaticamente
    %u - Inteiro decimal sem sinal (unsigned)
    %o - Inteiro octal (base 8)
    %x - Inteiro hexadecimal minúsculo (a-f)
    %X - Inteiro hexadecimal maiúsculo (A-F)

    Números com ponto flutuante:
    %f - Float/double em notação decimal
    %e - Notação científica minúscula (1.23e+02)
    %E - Notação científica maiúscula (1.23E+02)
    %g - Automático (%f ou %e, o mais curto)
    %G - Automático (%f ou %E, o mais curto)

    Caracteres e strings:
    %c - Um caractere
    %s - String (cadeia de caracteres)

    Ponteiros:
    %p - Endereço de ponteiro

    Especiais:
    %% - Imprime o símbolo %
    %n - Armazena número de caracteres impressos

    Modificadores de tamanho:
    %ld - Long int
    %lld - Long long int
    %lf - Double (no printf é igual a %f)
    %Lf - Long double
    %li - Long int

*/