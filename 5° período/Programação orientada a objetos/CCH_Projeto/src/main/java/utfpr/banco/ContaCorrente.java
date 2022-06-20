package utfpr.banco;

import utfpr.excecoes.SaldoInsuficienteException;

public class ContaCorrente extends ContaBancaria {
    private double tarifa;
    
    public ContaCorrente(int numero, Cliente titular, double saldo, double tarifa){
        super(numero,titular,saldo);
        this.tarifa = tarifa;
    }

    public double getTarifa() {
        return tarifa;
    }

    public void setTarifa(double tarifa) {
        this.tarifa = tarifa;
    }
    
    @Override
    public void processar(){
        try {
            this.sacar(tarifa);
        } catch (SaldoInsuficienteException ex) {
            System.out.println(ex);
        }
    }
    
    public String getInformacoes(){
        return "Tipo: CC, " + super.getInformacoes() + " Tarifa: R$ " + this.tarifa;
    }
}