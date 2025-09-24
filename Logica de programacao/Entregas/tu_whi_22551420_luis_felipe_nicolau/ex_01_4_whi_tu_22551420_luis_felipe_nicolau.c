#include <stdio.h>
#include <locale.h>
#define FLOAT "%f" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	float num, soma = 0;
	int contador = 0;
	char mais_um = 's';
	
	while (mais_um != 'n')
	{
		printf("\nEntre com o número: ");
		scanf(FLOAT, &num);
		soma += num;
		contador++;
		printf("\nAdicionar outro número?(s/n): ");
		mais_um = getche();
	}
	
	printf("\nMédia: %f", soma / contador);
	
}
