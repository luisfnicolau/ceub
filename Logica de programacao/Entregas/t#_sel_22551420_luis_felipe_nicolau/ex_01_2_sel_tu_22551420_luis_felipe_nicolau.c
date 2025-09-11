/*
 * Descrição: Calcula a idade do usuário baseado no ano de nascimento.
 * Autor: Luis Felipe Nicolau
 * Data: 11/09/2025
 */

#include <stdio.h>
#include <locale.h>

void main(void) {
	 setlocale(LC_ALL, "Portuguese");

	int ano_nascimento, ano_atual, idade;
	
	printf("\nDigite seu ano de nascimento: ");
	
	scanf("%d", &ano_nascimento);
	
	printf("\nDigite o ano atual: ");
	
	scanf("%d", &ano_atual);
	
	idade = ano_atual - ano_nascimento;
	
	printf("\nSeu ano de nascimento �: %d", ano_nascimento);
	printf("\nSua idade �: %d", idade);
	
	if(idade >= 16){
		printf("\nA idade � %d anos e j� pode votar", idade);
	} else {
		printf("\nA idade � %d anos e n�o pode votar", idade);
	}
}
