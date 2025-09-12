#include <stdio.h>

int main(void)
{
    int idade;
    float salario;
    char tem_fiador;
    int tempo_emprego;
    float valor_emprestimo;

    printf("=== ANÁLISE DE CRÉDITO BANCÁRIO ===\n");

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite seu salário: R$ ");
    scanf("%f", &salario);

    printf("Tem fiador? (s/n): ");
    scanf(" %c", &tem_fiador);

    printf("Tempo de emprego (meses): ");
    scanf("%d", &tempo_emprego);

    printf("Valor do empréstimo desejado: R$ ");
    scanf("%f", &valor_emprestimo);

    if ((idade >= 18 && idade <= 65) &&
        (salario >= 2000.0 || tem_fiador == 's') &&
        tempo_emprego >= 6 &&
        valor_emprestimo <= (salario * 5))
    {

        printf("\n✅ CRÉDITO APROVADO!\n");

        if (salario >= 5000.0 && tempo_emprego >= 24 && tem_fiador == 's')
        {
            printf("Taxa especial: 1.2%% ao mês\n");
        }
        else if (salario >= 3000.0 && tempo_emprego >= 12)
        {
            printf("Taxa normal: 2.5%% ao mês\n");
        }
        else
        {
            printf("Taxa padrão: 3.8%% ao mês\n");
        }
    }
    else
    {
        printf("\n❌ CRÉDITO NEGADO!\n");
        printf("Motivos possíveis:\n");

        if (!(idade >= 18 && idade <= 65))
        {
            printf("- Idade fora do limite (18-65 anos)\n");
        }
        if (!(salario >= 2000.0 || tem_fiador == 's'))
        {
            printf("- Salário baixo E sem fiador\n");
        }
        if (tempo_emprego < 6)
        {
            printf("- Pouco tempo de emprego (mín. 6 meses)\n");
        }
        if (valor_emprestimo > (salario * 5))
        {
            printf("- Valor solicitado muito alto (máx. 5x o salário)\n");
        }
    }

    if (!(idade < 18))
    {
        printf("\nVocê é maior de idade.\n");
    }

    if ((salario > 10000.0 && tem_fiador == 'n') ||
        (salario > 15000.0 && tempo_emprego > 36))
    {
        printf("Você se qualifica para conta VIP! 💎\n");
    }

    return 0;
}