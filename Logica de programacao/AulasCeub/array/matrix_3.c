#include <stdio.h>
#include <string.h>

void main (void) {
	int l, c;
	char nomes_alunos[4][10];
	for (l = 0; l < 4; l++) {
		printf("\n Digite o nome do aluno %d: ", l+1);
		gets(nomes_alunos[l]);
	}
	for (l = 0; l < 4; l++) {
		printf("\n O nome do aluno %d e %s", l + 1, nomes_alunos[l]);
	}
}
