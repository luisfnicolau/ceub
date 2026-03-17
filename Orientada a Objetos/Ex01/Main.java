import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite um numero positivo:");
        int numero = sc.nextInt();

        if (numero <= 0) {
            System.out.println("Número inválido. Por favor, digite um número maior que zero.");
            return;
        }
        for (int i = 1; i <= 10; i++) {
            int resultado = numero * i;
            String parOuImpar = (resultado % 2 == 0) ? "Par" : "Ímpar";
            System.out.println(numero + " x " + i + " = " + resultado + " - " + parOuImpar);
        }
    }
}