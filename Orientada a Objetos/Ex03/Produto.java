public class Produto {

    String nome;
    double preco;
    int quantidadeEmEstoque = 0;

    public Produto() {
    }

    public Produto(String nome, double preco) {
        this.nome = nome;
        this.preco = preco;
    }

    public double getPreco() {
        return preco;
    }

    public String getNome() {
        return nome;
    }

    public void setPreco(double preco) {
        if (preco < 0) {
            System.out.println("Preço inválido");
            return;
        }
        this.preco = preco;
    }

    public void setNome(String nome) {
        if (nome == null || nome.isEmpty()) {
            System.out.println("Nome inválido");
            return;
        }
        this.nome = nome;
    }

    public void adicionarEstoque(int quantidade) {
        if (quantidade > 0) {
            this.quantidadeEmEstoque += quantidade;
        }
    }

    public void vender(int quantidade) {
        if (quantidade > quantidadeEmEstoque) {
            System.out.println("Estoque insuficiente para a venda.");
            return;
        }
        this.quantidadeEmEstoque -= quantidade;
    }

    public void exibirResumo() {
        System.out.println("Produto: " + nome);
        System.out.printf("Preço: R$%.2f%n", preco);
        System.out.println("Quantidade em estoque: " + quantidadeEmEstoque);
    }
}