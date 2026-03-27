import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        float saldo = 500.00f;
        boolean looping = true;
        while (looping) {
            System.out.println("");
            System.out.printf("1 - Consultar Saldo\n2 - Realizar Depósito\n3 - Realizar Saque\n4 - Sair\n");
            int opcao = sc.nextInt();
            switch (opcao) {
                case 1:
                    System.out.printf("Saldo: R$ %.2f%n", saldo);
                    break;
                case 2:
                    System.out.print("Insira o valor do depósito: ");
                    float valorDeposito = sc.nextFloat();
                    if (valorDeposito < 0) {
                        System.out.println("Valor de depósito inválido");
                        break;
                    }
                    saldo += valorDeposito;
                    System.out.println("Saldo atualizado");
                    break;
                case 3:
                    System.out.print("Insira o valor do depósito: ");
                    float valorSaque = sc.nextFloat();
                    if (valorSaque < 0 || valorSaque > saldo) {
                        System.out.println("Valor de saque inválido");
                        break;
                    }
                    saldo -= valorSaque;
                    System.out.println("Saldo atualizado");
                    break;
                case 4:
                    looping = false;
                    break;
                default:
                    System.out.println("Opção inválida");
                    break;
            }
        }

    }    
}

