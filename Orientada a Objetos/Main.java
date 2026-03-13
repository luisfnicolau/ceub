import java.util.Scanner;

public class Main {
    Scanner sc = new Scanner(System.in);

    public static void main (String[] args) {
        /*
        System.out.print("Digite seu peso: ");
        int peso = sc.nextInt();

               Operators	Associativity	Type
        ++, –	Right to Left	Unary postfix
        ++, --, +, -, !	Right to Left	Unary prefix
        /, *, %	Left to Right	Multiplicative
        +, -	Left to Right	Additive
        <, <=, >, >=	Left to Right	Relational
        ==, !==	Left to Right	Equality
        &	Left to Right	Boolean Logical AND
        ^	Left to Right	Boolean Logical Exclusive OR
        |	Left to Right	Boolean Logical Inclusive OR
        &&	Left to Right	Conditional AND
        ||	Left to Right	Conditional OR
        ?:	Right to Left	Conditional
        =, +=, -=, *=, /=, %=	Right to Left	Assignment
        */

        /* 
        if (peso >= 120 && peso < 500) {
            System.out.println("Pode não");
        } else if (peso < 120 && peso > 0) {
            System.out.println("Ta liberado");
        } else {
            System.out.println("Viajou");
        }

        switch(peso) {
            case 10:
                System.out.println("Peso 10");
                break;
           case 20:     
                System.out.println("Peso 10");
                break;
            default:
                System.out.println("Peso 10");
        }

        if (peso == 10) {
            System.out.println("Pode não");
        } else if (peso == 20) {
            System.out.println("Ta liberado");
        }
        */

        somaDeNumeros();
    }

    public static void somaDeNumeros() {
        Scanner sc = new Scanner(System.in);
        float somatorio = 0;
        int qtdNum = 0;
        System.out.println("Quantos números: ");
        qtdNum = sc.nextInt();


        for (int i = 0; i < qtdNum; i++) {
            System.out.println("Digite o número " + (i + 1) + ":");
            float num = sc.nextFloat();
            somatorio += num;
        }
        if (qtdNum == 0) {
            qtdNum = 1;
        }
        System.out.println("Somatório: " + somatorio);
        System.out.println("Média: " + somatorio / qtdNum);
        sc.close();
    }

    public static void searchFruit() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Digite o nome de uma fruta: ");
        String fruta = sc.nextLine();

        fruta = fruta.toLowerCase();

        String[] possibleOptions = {"banana", "maca", "abacate", "acai"};

        int[] ocurrences = {0, 0, 0, 0};

        String[][] combinations = new String[possibleOptions.length][];

        for (int index = 0; index < possibleOptions.length; index++) {
            combinations[index] = new String[possibleOptions[index].length()];
            for (int cIndex = 0; cIndex < possibleOptions[index].length(); cIndex++) {
                int finalIndex = cIndex + 2;
                if (finalIndex >  possibleOptions[index].length()) {
                    finalIndex = cIndex;
                }
                
                String piece = possibleOptions[index].substring(cIndex, finalIndex);
                combinations[index][cIndex] = piece;
            }
        }

        for (int index = 0; index < possibleOptions.length; index++) {
            for (int cIndex = 0; cIndex < possibleOptions[index].length(); cIndex++) {
                System.out.println(combinations[index][cIndex]);
                if (fruta.contains(combinations[index][cIndex])) {
                    ocurrences[index]++;
                }
            }
            System.out.println("occur: "+ ocurrences[index]);
        }


        int greaterIndex = 0;
        int greatValue = 0;

        for (int index = 0; index < ocurrences.length; index++) {
            if (ocurrences[index] > greatValue) {
                greatValue = ocurrences[index];
                greaterIndex = index;
            }
        }

        System.out.println("resultado: " + possibleOptions[greaterIndex]);

        sc.close();
    }
}