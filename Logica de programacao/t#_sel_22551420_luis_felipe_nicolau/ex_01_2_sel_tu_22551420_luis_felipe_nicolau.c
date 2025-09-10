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
	
	printf("\nSeu ano de nascimento é: %d", ano_nascimento);
	printf("\nSua idade é: %d", idade);
	
	if(idade >= 16){
		printf("\nA idade é %d anos e já pode votar", idade);
	} else {
		printf("\nA idade é %d anos e não pode votar", idade);
	}
}
