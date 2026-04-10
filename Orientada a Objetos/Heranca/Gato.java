public class Gato extends Animal {
    public Gato(String nome, int idade) {
        super(nome, idade);
    }

    @Override
    public void emitirSom() {
        super.emitirSom();
        System.out.println("Mi mi mi au");
    }
}