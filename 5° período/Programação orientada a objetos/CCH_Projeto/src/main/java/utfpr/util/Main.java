package utfpr.util;

import utfpr.banco.Banco;
import utfpr.gui.TelaPrincipal;

public class Main {
    public static void main(String[] args) {
        DataProvider provider = new DataProvider();
        Banco banco = provider.criarBanco("Movimentação");
        banco.listarContas();
        banco.listarClientes();
        
        TelaPrincipal objPrincipal = new TelaPrincipal();
        objPrincipal.setBanco(banco);
        objPrincipal.setVisible(true);
    }
}