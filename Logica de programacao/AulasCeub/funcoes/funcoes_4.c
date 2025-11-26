#include <stdio.h>
#include <locale.h>

void main (void) {
	setlocale(LC_ALL, "portuguese");
	
	int strleng(char vet[]), cont=0;
	char nome[40];
	printf("\n Digite um nome: ");
	gets(nome);
	cont=strleng(nome);
	printf("\n O vetor possui %d caracteres", cont);
}

int strleng(char vet[]) {
	int i=0;
	for (i=0;vet[i]!=0;i++){
	};
	return(i);
}
