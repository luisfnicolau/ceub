#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void) {
	int c;
	int getpos(void);
	puts("DIGITE QUALQUER LETRA DO ALFABETO");
	c=getpos();
	printf("\nO CARACTER ESTA NA POSICAO (%d) DO ALFABETO\n", c);
}

int getpos(void) {
	char c;
	c=getche();
	if (c < 97) {
		c=tolower(c);
	}
	return (26-('z'-c));
}
