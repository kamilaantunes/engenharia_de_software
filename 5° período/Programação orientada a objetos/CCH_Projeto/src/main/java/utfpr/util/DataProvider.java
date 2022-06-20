package utfpr.util;

import java.util.ArrayList;
import java.util.Random;
import utfpr.banco.Banco;
import utfpr.banco.Cliente;
import utfpr.banco.ContaBancaria;
import utfpr.banco.ContaCorrente;
import utfpr.banco.ContaPoupanca;
import utfpr.excecoes.SaldoInsuficienteException;

/**
 *
 * @author evand
 */
public class DataProvider {
    private ArrayList<Cliente> clientes = new ArrayList<>();
    private ArrayList<ContaBancaria> contas = new ArrayList<>();
    private final int NUM_CC = 10, NUM_CP = 10;
    
    public Banco criarBanco(String nomeBanco){
        Banco banco = new Banco(nomeBanco);
        
        criarClientes();
        criarContaCorrente();
        criarContaPoupanca();
        
        // adicionando as contas criadas no banco.
        for (ContaBancaria c : contas){
            banco.adicionar(c);
        }
        
        gerarMovimentacoes(banco);
        
        return banco;
    }
    
    public void criarContaCorrente(){
        for (int i=0; i<NUM_CC; i++){
            contas.add(
                new ContaCorrente(i+1, clientes.get(i), 100, 35)
            );
        }
    }
    
    public void criarContaPoupanca(){
        for (int i=0; i<NUM_CP; i++){
            contas.add(
                new ContaPoupanca(i+1, clientes.get(i), 100, 0.5)
            );
        }
    }
    
    public void criarClientes(){
        int NUM_CLI = NUM_CP > NUM_CC ? NUM_CP : NUM_CC; // cria um número de clientes suficiente de acordo com o numéro de contas.
        int cod;
        for (int i=0; i<NUM_CLI; i++){
            cod = i + 1;
            clientes.add(new Cliente(cod, "Fulano " + cod, "Rua " + cod));
        }
    }
    
    private void gerarMovimentacoes(Banco banco){
        Random rand = new Random(0);
        int tipo, sucesso = 0;
        
        for (ContaBancaria c : contas){
           
            for (int i=0; i<5; i++){
                tipo = rand.nextInt(2);
                //System.out.println("Tipo: " + tipo);
                if (tipo == 0) { // sacar

                    try {    
                        c.sacar(rand.nextInt(100));
                        sucesso++;
                    } catch (SaldoInsuficienteException ex) {
                        System.out.println(ex);
                    }
                    
                } else { // depositar

                    c.depositar(rand.nextInt(100));
                    sucesso++;
                }
            }
            
        }
        System.out.printf("gerarMovimentacoes() - transações realizadas com sucesso: (%d) / (%d)\n", sucesso, 5 * contas.size());
    }
}