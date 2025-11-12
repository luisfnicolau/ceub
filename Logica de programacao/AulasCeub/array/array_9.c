#include <stdio.h>
#include <string.h>

void main(void) {
	int i;
	char vet[40], vet1[40];
	printf("Digite seu nome: ");
	gets(vet);
	strcpy(vet1, vet);
	puts(vet);
	puts(vet1);
}
