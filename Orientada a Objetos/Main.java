import java.util.Scanner;

public class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Digite seu peso: ");
        int peso = sc.nextInt();

        /*         Operators	Associativity	Type
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
    }
}