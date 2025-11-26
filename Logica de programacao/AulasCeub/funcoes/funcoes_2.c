#include <stdio.h>
#include <conio.h>

void main (void) {
	int a, b, c;
	int soma(int x, int y);
	
	puts("DIGITE O PRIMEIRO NUEMRO: ");
	scanf("%d", &a);
	puts("DIGITE O SEGUNDO NUEMRO: ");
	scanf("%d", &b);
	printf("\nSOMA: %d\n", soma(a, b));
}

int soma(int x, int y) {
	int result;
	result = x + y;
	return result;
}
