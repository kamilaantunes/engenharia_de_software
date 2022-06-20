package utfpr.banco;

public class Cliente {
    private int cod;
    private String nome;
    private String endereco;

    public Cliente(int cod, String nome, String endereco) {
        this.cod = cod;
        this.nome = nome;
        this.endereco = endereco;
    }

    public int getCod() {
        return cod;
    }

    public void setCod(int cod) {
        this.cod = cod;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    @Override
    public String toString() {
        return "Cod: " + this.getCod() + " Nome: " + this.getNome();
    }
    
    
}