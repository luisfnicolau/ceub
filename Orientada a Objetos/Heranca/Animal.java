public class Animal {
    // Protege a variavel e deixa visivel somente as classes da mesma pasta, que seria do mesmo pacote
    // O private não permite acesso nem de classes que herdaram o Animal
    protected String nome;
    protected int idade;
    //Constructor
    public Animal(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    //Método Genérico
    public void emitirSom(){
        System.out.println("Animal disse: " + nome);
    }

    public void mostrarInfo(){
        System.out.println("Nome: " + nome);
        System.out.println("Idade: " + idade);
    }
}
