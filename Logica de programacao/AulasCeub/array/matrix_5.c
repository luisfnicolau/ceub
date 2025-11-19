#include <stdio.h>
#include <string.h>

void main (void) {
	int l, c, i;
	char nomes_alunos[4][10];
	for (l = 0; l < 4; l++) {
		printf("\n Digite o nome do aluno %d: ", l+1);
		for (c = 0; c < 9; c++) {
			nomes_alunos[l][c] = getche();
			if (nomes_alunos[l][c] == 13) {
				break;
			}
			if (nomes_alunos[l][c] == 8) {
				printf(" \b \b");
				c = c - 2;
			}
		}
		nomes_alunos[l][c] = '\0';
	}
	for (l = 0; l < 4; l++) {
		printf("\n O nome do aluno %d e %s", l + 1, nomes_alunos[l]);
	}
}
