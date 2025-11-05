#include <stdio.h>
#include <locale.h>

void main(void) {
	int i;
	
	char vet[] = "ceub";
	
	printf("Vetor original: %s", vet);
	
	for (i = 0; vet[i] != '\0'; i++) {
		vet[i] = vet[i] - 32;
	}
	
	printf("\nVetor final: %s", vet);
	
}
