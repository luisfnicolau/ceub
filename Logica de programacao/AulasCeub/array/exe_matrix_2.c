#include <stdio.h>
#include <string.h>

#define gotoxy(x, y) printf("\033[%d;%dH", (y), (x))

void main(void){
	int minha_matriz[3][4];
	int i, j;
	char aux;
	
	printf("Insira os numeros: \n");
	
	for (j = 0; j < 4; j++) {
		for (i = 0; i < 3; i++) {
			if (j == 0) {
				printf("|");
			}
			gotoxy(j + 2, i + 2);
			minha_matriz[i][j] = getche() - '0';

			if (j == 3) {
				printf("|");
			}
			gotoxy(j, i + 3);
		}
		gotoxy(i - 1, j + 2);
	}
	
	printf("\n\n");
	
	for (i = 0; i < 3; i++) {
		printf("|");
		for (j = 0; j < 4; j++) {
			printf("%d", minha_matriz[i][j]);
		}
		printf("|\n");
	} 
}
