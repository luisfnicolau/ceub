#include <stdio.h>
#include <locale.h>

void main(void) {
	int i;
	
	char palavra1[5] = {'a', 'b', 'c'};
	char palavra2[5] = "abc\n";
	
	for(i = 0; i < 5; i++) {
		printf("\n Palavra 1: %c", palavra1[i]);
	}
	
	for(i = 0; i < 5; i++) {
		printf("\n Palavra 2: %d", palavra2[i]);
	}
}
