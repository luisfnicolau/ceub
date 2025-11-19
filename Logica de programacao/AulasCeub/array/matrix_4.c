#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (void) {
	int i, c;
	char mencoes[5][2][3] = {{"MM", "SS"}, {"MM", "SS"}, {"MM", "SS"}, {"MM", "SS"}, {"MM", "SS"}};
	char aux[10];
	
	for (i = 0; i < 5; i++) {
		printf ("\n Aluno %d \nmencao 1: %s \nmencao 2: %s", i+1, mencoes[i][0], mencoes[i][1]);
	}
}
	
	
