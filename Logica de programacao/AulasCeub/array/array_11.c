#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

void main(void) {
	char prod[40], aux[10];
	float valor;
	int qtd;
	setlocale(LC_ALL, "portuguese");
	printf("\n Digite o nome do produto: ");
	gets(prod);
	printf("\n Digite a quantidade: ");
	qtd=atoi(gets(aux));
	printf("\n Digite o valor do produto: ");
	valor = atof(gets(aux));
	printf("\n O valor a ser pago pelo produto %s será de R$ %.2f", prod, qtd*valors);
}
