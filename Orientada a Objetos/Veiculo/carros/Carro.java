package carros;

import veiculos.Veiculo;

public class Carro extends Veiculo {
    public Carro(String nome) {
        super(nome);
    }

    public void mover() {
        System.out.println("Vruummm!");
    }
}