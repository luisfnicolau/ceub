#include <stdio.h>
#include <locale.h>

void main(void) {
	int i;
	// Lista de 10 elementos inteiros
	int quad[10];
	for(i = 0; i < 15; i++) {
		quad[i] = i*i;
	}
	for(i = 0; i < 15; i++) {
		printf("\n O quadrado de %d = %d", i, quad[i]);
	}
}
