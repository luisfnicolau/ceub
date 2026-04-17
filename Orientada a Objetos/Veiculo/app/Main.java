package app;

import veiculos.terrestre.Carro;

public class Main {
    public static void main(String[] args) {
        Carro opalao = new Carro("Opala", 4 "Gasolina");

        opalao.acelerar(120);
        opalao.mover();
        opalao.desacelerar(5);
        opalao.mover();
    }    
}

/* acelerar
mover
desacelerar
mover */