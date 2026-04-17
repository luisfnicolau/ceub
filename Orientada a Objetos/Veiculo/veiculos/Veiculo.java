package veiculos;

// Método abstrato, não é possível instanciar, somente outras classes podem herdar ele, e pode ser declarado como um tipo
public abstract class Veiculo {

    protected String nome;
    protected double velocidade;

    public Veiculo(String nome){
        this.nome = nome;
        this.velocidade = 0;
    }

    public void acelerar(double incremento){
        if(incremento > 0){
            velocidade += incremento;
        }
    }

    public void desacelerar(double drecremento){
        if (nome == "Opala") {
            System.out.println("Opala não freia");
            return;
        }
        if(drecremento > 0){
            velocidade -= drecremento;
            if(velocidade < 0){
                velocidade = 0;
            }
        }
    }


    //Método abstrato, não seio que ele vai fazer nas subclasses, mas é obrigatorio declarar esse método
    public abstract void mover();

    public void mostrarInfo() {
        System.out.println("Nome: " + nome);
        System.out.println("Velocidade: "+velocidade);

    }
}