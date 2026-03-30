/*
Crie uma classe principal (Main) para testar sua classe Produto. Instancie um produto, adicione estoque, tente vender uma quantidade válida, tente vender uma quantidade maior que o estoque e exiba o resumo ao final.
Teste as possibilidades positivas, negativas e casos extremos.
*/


public class Main {
    public static void main(String[] args) {
        Produto produto = new Produto();
        produto.setNome("Camiseta");
        produto.setPreco(29.99);
        produto.adicionarEstoque(100);
        produto.vender(10);
        produto.exibirResumo();

        produto.vender(150);
        produto.exibirResumo();


        produto.setPreco(-5.00);
        produto.exibirResumo();


        produto.setNome("");


        produto.setNome(null);

        produto.adicionarEstoque(0);
        produto.exibirResumo();

        produto.adicionarEstoque(-10);
        produto.exibirResumo();

        produto.vender(90);
        produto.exibirResumo();

        produto.vender(1);

        Produto produto2 = new Produto("Tênis", 199.90);
        produto2.adicionarEstoque(50);
        produto2.vender(25);
        produto2.exibirResumo();

        produto2.setPreco(0);
        produto2.exibirResumo();
    }
}