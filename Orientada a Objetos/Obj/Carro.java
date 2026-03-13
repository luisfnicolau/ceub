public class Carro {
    //Atributos (variáveis)
    private String marca;
    private String modelo;
    private int ano;
    private double velocidadeMaxima;
    private boolean automatico;

    //Constructor
    public Carro(String marca, String MODELO, int ANO) {
        this.marca = marca;
        this.modelo = MODELO;
        this.ano = ANO;
        this.velocidadeMaxima = 200;
        this.automatico = true;
    }

    // Métodos da Classe Carro
    // Sem retorno
    public void acelerar() {
        System.out.println("VRUUUMMMM!!");
    }


    //Com retorno
    public String mostrarMarca() {
        return this.marca;
    }
}
