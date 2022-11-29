// Até 10 unidades - sem desconto
// De 11 a 20 unidades - 10% de desconto
// De 21 a 50 unidades - 20% de desconto
// Acima de 51 unidades - 25% de desconto

import javax.swing.JOptionPane;

public class Supermercado{
    private String nome;
    private float preco;
    private double precoTotal;
    private int quantidade;
    private double desconto;

    public Desconto(){}
    
    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public float getPreco(){
        return preco;
    }

    public void setPreco(float preco){
        this.preco = preco;
    }

    public int getQuantidade(){
        return quantidade;
    }

    public void setQuantidade(int quantidade){
        this.quantidade = quantidade;
    }

    public double getPrecoTotal(){
        if (quantidade > 10 && quantidade <= 20){
            return this.precoTotal = preco * quantidade;
        } else if (quantidade > 20 && quantidade <= 50){
            return (this.preco * quantidade);
        } else if (quantidade > 50){
            return (this.preco * quantidade);
        }

        return preco;
    }

    public void setPrecoTotal(float precoTotal){
        this.precoTotal = preco * quantidade;
    }

    public void status(){
        System.out.println("Nome do produto: " + this.getNome());
        System.out.println("Preço: R$ " + this.getPreco());
        System.out.println(this.getQuantidade() + "quantidades");
        System.out.println("Valor com desconto " + this.getPrecoTotal() + "R$ ");
        System.out.println("Desconto é de R$ " + this.getPrecoTotal() * 0.1);
    }
}