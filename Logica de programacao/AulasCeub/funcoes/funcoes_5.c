#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

void main (void) {
	setlocale(LC_ALL, "portuguese");
	
	char aux[10], nome[40];
	printf("\n Digite um nome: ");
	gets(nome);
	tomai(nome);
	
	printf("\n O nome em maiúsculo é %s", nome);
}

int tomai(char nome[]) {
	int i;
	for (i=0;nome[i]!=0;i++){
		if (nome[i] > 96) {
			nome[i] = toupper(nome[i]);
		} 
	}
}
