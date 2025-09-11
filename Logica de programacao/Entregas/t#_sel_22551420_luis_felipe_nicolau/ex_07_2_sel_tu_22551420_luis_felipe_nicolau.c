/*
 * Descrição: Calcula a média aritimetica de notas.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void) {
    setlocale(LC_ALL, "Portuguese");
    
    float nota1, nota2, media;
    int peso1, peso2;
    
    printf("\nPrimeira nota: ");
    scanf("%f", &nota1);
    
    printf("\nPeso da primeira nota: ");
    scanf("%i", &peso1);
    
    printf("\nSegunda nota: ");
    scanf("%f", &nota2);
    
    printf("\nPeso da segunda nota: ");
    scanf("%i", &peso2);
    
    media = ((nota1 * peso1) + (nota2 * peso2)) / (peso1 + peso2);
    
    printf("\nMedia: %.2f ", media);
    
    if (media >=5) {
    	printf("Aluno aprovado");
	} else {
		printf("Aluno reprovado");
	}
}
