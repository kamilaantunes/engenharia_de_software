package utfpr.gui;

import java.util.ArrayList;
import javax.swing.JLabel;
import javax.swing.JRootPane;
import javax.swing.plaf.basic.BasicInternalFrameUI;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;
import utfpr.banco.ContaBancaria;
import utfpr.banco.ContaCorrente;

public class ListaContas extends javax.swing.JInternalFrame {

    ArrayList<ContaBancaria> contas;

    /**
     * Creates new form ListaContas
     */
    public ListaContas(ArrayList dados) {
        initComponents();
        remove_title_bar();
        this.contas = dados;
        carregarDados();
    }

    private void carregarDados() {
        // Transformando os dados dos clientes p preenchimento na tabela
        TableModel tm = toTableModel(contas);
        tblContas.setModel(tm);
        configurarTabela();
    }

    private TableModel toTableModel(ArrayList<ContaBancaria> contasBancarias) {

        DefaultTableModel model = new DefaultTableModel(
                new String[]{"ID", "Tipo", "Titular", "Saldo"}, 0) {
            Class[] types = new Class[]{String.class, String.class, String.class, Double.class}; // Formato de apresentação das colunas da tabela
            boolean[] canEdit = new boolean[]{false, false, false, false}; // Impossibilitando a edição da tabela

            public Class getColumnClass(int columnIndex) {
                return types[columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit[columnIndex];
            }
        };

        String contaTipo;

        for (ContaBancaria conta : contas) {
            if (conta instanceof ContaCorrente) {
                contaTipo = "Conta corrente";
            } else {
                contaTipo = "Conta poupança";
            }
            model.addRow(new Object[]{conta.getNumero(), contaTipo, conta.getTitular().getNome(), conta.getSaldo()});

        }
        return model;
    }

    private void configurarTabela() {
        //Ajusta o alinhamento do texto do cabeçalho para a esquerda
        DefaultTableCellRenderer renderer = (DefaultTableCellRenderer) tblContas.getTableHeader().getDefaultRenderer();
        renderer.setHorizontalAlignment(JLabel.CENTER);

        //Ajusta o tamanho das colunas para ficar mais bonito
        if (tblContas.getColumnModel().getColumnCount() > 0) {
            tblContas.getColumnModel().getColumn(0).setMinWidth(50);
            tblContas.getColumnModel().getColumn(0).setMaxWidth(100);
            tblContas.getColumnModel().getColumn(1).setMinWidth(100);
            tblContas.getColumnModel().getColumn(2).setMinWidth(100);
        }

    }

    private void remove_title_bar() {
        putClientProperty("ListaContas.isPalette", Boolean.TRUE);
        getRootPane().setWindowDecorationStyle(JRootPane.NONE);
        ((BasicInternalFrameUI) this.getUI()).setNorthPane(null);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        lblBancoNome = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        tblContas = new javax.swing.JTable();

        setBackground(new java.awt.Color(255, 255, 255));
        setBorder(null);

        lblBancoNome.setBackground(new java.awt.Color(0, 0, 0));
        lblBancoNome.setFont(new java.awt.Font("Arial", 1, 36)); // NOI18N
        lblBancoNome.setForeground(new java.awt.Color(255, 255, 255));
        lblBancoNome.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        lblBancoNome.setText("Contas cadastradas no banco POO");
        lblBancoNome.setAutoscrolls(true);
        lblBancoNome.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        lblBancoNome.setMaximumSize(new java.awt.Dimension(136, 42));
        lblBancoNome.setMinimumSize(new java.awt.Dimension(136, 42));
        lblBancoNome.setOpaque(true);
        lblBancoNome.setPreferredSize(new java.awt.Dimension(136, 42));

        tblContas.setAutoCreateRowSorter(true);
        tblContas.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        tblContas.setFont(new java.awt.Font("Arial", 0, 12)); // NOI18N
        tblContas.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null}
            },
            new String [] {
                "ID conta", "Tipo da conta", "Títular da conta", "Saldo", "Rendimento"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.Double.class, java.lang.Double.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, true, true
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tblContas.setAutoscrolls(false);
        tblContas.setGridColor(java.awt.SystemColor.controlLtHighlight);
        tblContas.setOpaque(false);
        tblContas.getTableHeader().setReorderingAllowed(false);
        tblContas.setUpdateSelectionOnSort(false);
        jScrollPane1.setViewportView(tblContas);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(lblBancoNome, javax.swing.GroupLayout.DEFAULT_SIZE, 749, Short.MAX_VALUE)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(lblBancoNome, javax.swing.GroupLayout.PREFERRED_SIZE, 64, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 269, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(26, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel lblBancoNome;
    private javax.swing.JTable tblContas;
    // End of variables declaration//GEN-END:variables
}