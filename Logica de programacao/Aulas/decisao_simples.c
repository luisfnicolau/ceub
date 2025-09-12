#include <stdio.h>

int main(void)
{
    int idade;

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    if (idade <= 10)
    {
        printf("Você é uma criança\n");
    }
    else if (idade <= 18)
    {
        printf("Você é um adolescente\n");
    }
    else if (idade <= 60)
    {
        printf("Você é um adulto\n");
    }
    else
    {
        printf("Você é um idoso\n");
    }

    printf("\nFim");
}

// if -> se
// else -> senão

// if (condicao)
//     acao se condicao for verdade

// == -> igualdade
// != -> diferente
// < -> menor que
// > -> maior que
// <= -> menor ou igual que
// >= -> maior ou igual que

// AND -> e => &&
// OR -> ou => ||
// NOT -> negação = > !