#include <stdio.h>
#include <string.h>

void main(void) {
	int i;
	char vet[40];
	printf("Digite seu nome: ");
	gets(vet);
	puts(vet);
	printf("\n O seu nome %s possui %d caracteres", vet, strlen(vet));
}
