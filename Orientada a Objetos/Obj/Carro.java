public class Carro {
    //Atributos (variáveis)
    private String marca;
    private String modelo;
    int ano;
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

    public int getAno() {
        return this.ano;
    }

    public void setAno(int novoAno) {
        this.ano = novoAno;
    }


    //Com retorno
    private String mostrarMarca() {
        return this.marca;
    }

    public void mostrarInfo() {
        System.out.println("Marca: " + this.mostrarMarca());
        System.out.println("Modelo: " + this.modelo);
        System.out.println("Ano de Fabricação: " + this.ano);
        System.out.println("Velocidade Máxima: " + this.velocidadeMaxima);
        System.out.println("Automático: " + this.automatico);

    }
}
