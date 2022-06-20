package utfpr.banco;

public class ContaPoupanca extends ContaBancaria {
    private double rendimento;
    
    public ContaPoupanca(int numero, Cliente titular, double saldo, double rendimento){
        super(numero,titular,saldo);
        this.rendimento = rendimento;
    }

    public double getRendimento() {
        return rendimento;
    }

    public void setRendimento(double rendimento) {
        this.rendimento = rendimento;
    }
    
    @Override
    public void processar(){
        double valorQueRendeu = this.getSaldo() * rendimento / 100;
        this.depositar(valorQueRendeu);
    }
    
    public String getInformacoes(){
        return "Tipo: CP, " + super.getInformacoes() + " Rendimento: % " + this.rendimento;
    }
}