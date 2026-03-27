public class Cachorro extends Animal {
    public String raca;

    public Cachorro(String nome, int idade, String raca) {
        super(nome, idade);
        this.raca = raca;
    }

    //Sobrescrita do método emitirSom(Override)
    @Override
    public void emitirSom(){
        System.out.println("Au au");
    }

    public void abanarCauda(){
        System.out.println(nome + " esta abanando a cauda");
    }

    //Sobrescrita do método emitirSom(Override)
    @Override
    public void mostrarInfo(){
        super.mostrarInfo();
        System.out.println("Raça: " + raca);
    }
    
}
