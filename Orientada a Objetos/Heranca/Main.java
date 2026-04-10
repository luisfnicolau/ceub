

public class Main {
    public static void main(String[] args) {
        Animal animal = new Animal("Jorge", 12);
        animal.emitirSom();
        animal.mostrarInfo();

        Cachorro cachorro = new Cachorro("Toto", 10, "Golden");
        cachorro.emitirSom();
        cachorro.abanarCauda();
        cachorro.mostrarInfo();

        Gato gato = new Gato("Furry", 4);
        gato.emitirSom();
    }    
}
