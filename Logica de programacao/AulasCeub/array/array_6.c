#include <stdio.h>
#include <locale.h>

void main(void) {
	int i, contador = 0;
	char palavra[100] = "ceub";
	
	printf("\n Digite seu nome: ");
	gets(palavra);
	
	for (i = 0; palavra[i] != '\0'; i++) {
		if (palavra[i] >= 97 && palavra[i] <= 122) {
			palavra[i] -= 32;
			contador++;
		}
	}
	
	printf("\nVetor em maiusculas e %s", palavra);
	printf("\nForam modificados %d letras", contador);
	
}
