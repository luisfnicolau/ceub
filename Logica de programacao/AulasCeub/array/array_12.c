#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void main(void) {
	char palavra[40];
	int charNum;
	setlocale(LC_ALL, "portuguese");
	printf("\n Digite a palavra: ");
	gets(palavra);
	charNum = strlen(palavra);
	printf("\n");
	for (; charNum >= 0; charNum--) {
		printf("%c", palavra[charNum]);
	}
}
