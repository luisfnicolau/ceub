#include <stdio.h>
#include <string.h>
#include <locale.h>

void main(void) {
	setlocale(LC_ALL, "portuguese");
	int i;
	char vet[40], vet1[40];
	printf("Digite uma frase: ");
	gets(vet);
	printf("\nDigite outra frase: ");
	gets(vet1);
	strcmp(vet1, vet);
	if (strcmp(vet1, vet) == 0) {
		printf("Tudo igual");
	} else if(strcmp(vet1, vet) == 1) {
		printf("\n Não são iguais mas ta em ordem");
	} else {
		printf("\n Não são iguais e não ta em ordem");
	}
}
