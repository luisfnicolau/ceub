#include <stdio.h>
#include <locale.h>

void main(void) {
	int i;
	// Lista de 10 elementos inteiros
	int quad[10] = {1,2,3,4,5,6,7,8,9,10};
	for(i = 0; i < 10; i++) {
		printf("\n O valor armazenado no elemento de indice %d é %d", i, quad[i]);
	}
}
