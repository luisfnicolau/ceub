/*
 * Descri√ß√£o: Exibe se o usu√°rio teve lucro basedo nos valoes de compra e venda.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void) {
    setlocale(LC_ALL, "Portuguese");
    float valorCompra, valorVenda;
    
    printf("\nValor da compra: ");
    scanf("%f", &valorCompra);
    
    printf("\nValor da venda: ");
    scanf("%f", &valorVenda);
    
    printf("\nValor da compra: %.2f", valorCompra);
    printf("\nValor da venda: %.2f", valorVenda);
    
    if (valorCompra > valorVenda) {
    	printf("\nTeve prejuÌzo");
	} else if (valorCompra < valorVenda) {
		printf("\nTeve lucro");
	} else {
		printf("\nOs valores s„o iguais");
	}
}
