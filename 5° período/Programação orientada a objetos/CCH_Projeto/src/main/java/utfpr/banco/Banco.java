package utfpr.banco;

import java.util.ArrayList;
import java.util.HashMap;

public class Banco {

    private String nome;
    private ArrayList<ContaBancaria> contas;

    public Banco(String nome) {
        this.nome = nome;
        this.contas = new ArrayList<>();
    }

    public void adicionar(ContaBancaria novaConta) {
        if (novaConta.getNumero() == 0) {
            System.out.println("Erro: conta tem que ter um número!");
        } else {
            this.contas.add(novaConta);
        }
    }

    public ContaBancaria getConta(int numero) {
        for (ContaBancaria conta : contas) {
            if (conta.getNumero() == numero) {
                return conta;
            }
        }
        return null;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    // IMPLEMENTAR...
    // remover
    // saldo de contas poupança
    // saldo de contas corrente
    // saldo de todas contas
    
    public void listarContas() {
        System.out.println("Banco: " + this.nome);
        System.out.println("Lista de contas...");
        for (ContaBancaria conta : contas) {
            System.out.println(conta.getInformacoes());
        }
    }
    
    public ArrayList<ContaBancaria> listarContasBancarias(){
    ArrayList<ContaBancaria> contasBancarias = new ArrayList();
    for(ContaBancaria conta : contas){
        contasBancarias.add(conta);
    }
    return contasBancarias;
}


    public ContaBancaria getContaMaiorSaldo() {
        ContaBancaria contaRetorno = null;

        for (ContaBancaria conta : contas) {

            if (contaRetorno == null || conta.getSaldo() > contaRetorno.getSaldo()) {
                contaRetorno = conta;
            }
        }
        return contaRetorno;
    }

    public ContaBancaria getContaMenorSaldo() {
        ContaBancaria contaRetorno = null;

        for (ContaBancaria conta : contas) {

            if (contaRetorno == null || conta.getSaldo() < contaRetorno.getSaldo()) {
                contaRetorno = conta;
            }
        }
        return contaRetorno;
    }

    public double getSaldoMedioContas() {
        double saldoMedio = 0;

        for (ContaBancaria conta : contas) {
            saldoMedio += conta.getSaldo();
        }

        if (!contas.isEmpty()) {
            saldoMedio = saldoMedio / contas.size();
        }

        return saldoMedio;
    }

    public double getSaldoMedioContasCorrente() {
        double saldoMedio = 0;
        Integer quantidade = 0;

        for (ContaBancaria conta : contas) {
            if (conta instanceof ContaCorrente) {
                quantidade++;
                saldoMedio += conta.getSaldo();
            }
        }

        if (quantidade > 0) {
            saldoMedio = saldoMedio / quantidade;
        }

        return saldoMedio;
    }

    public double getSaldoMedioContasPupanca() {
        double saldoMedio = 0;
        Integer quantidade = 0;

        for (ContaBancaria conta : contas) {
            if (conta instanceof ContaPoupanca) {
                quantidade++;
                saldoMedio += conta.getSaldo();
            }
        }

        if (quantidade > 0) {
            saldoMedio = saldoMedio / quantidade;
        }

        return saldoMedio;
    }

    public HashMap listarClientes() {

        HashMap<Integer, Cliente> clientes = new HashMap();

        for (ContaBancaria conta : contas) {
            Cliente titular = conta.getTitular();

            if (!clientes.containsKey(titular.getCod())) {
                clientes.put(titular.getCod(), titular);
            }
        }

        return clientes;
    }

}