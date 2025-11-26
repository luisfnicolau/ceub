#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main (void) {
	int i, c;
	float notas_al[5][2] = {0};
	char aux[10];
	for (i = 0; i < 5; i++) {
			printf("\n A média do aluno %d é %.2f", i+1, (notas_al[i][0]+notas_al[i][1])/2.0);
	}
}
