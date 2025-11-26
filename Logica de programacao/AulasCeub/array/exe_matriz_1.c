#include <stdio.h>
#include <string.h>

void main(void){
	int minha_matriz[3][4];
	int i, j;
	char aux;
	
	printf("Insira os numeros: \n");
	
	for (i = 0; i < 3; i++) {
		printf("|");
		for (j = 0; j < 4; j++) {
			 minha_matriz[i][j] = getche(aux) - '0';
		}
		printf("|\n");
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
