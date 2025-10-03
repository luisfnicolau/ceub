/*
Autor: Luis Felipe Moraes Nicolau
Data: 03/10/2025
Calcula a média aritmética de uma turma com 4 alunos
*/

#include <stdio.h>
#include <locale.h>
#define FLOAT "%f" 

void main (void){
	setlocale(LC_ALL, "Portuguese");
	float nota, soma = 0, media;
	int contador = 50;
	
	while (contador > 0)
	{
		printf("\nDigite a nota do aluno número %d: ", 51 - contador);
		scanf(FLOAT, &nota);
		soma += nota;
		contador--;
	}
	
	media = soma / 50;
	printf("\nMédia da turma = %.2f", media);
	
}
