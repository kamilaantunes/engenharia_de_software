#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <locale.h>

#define TAMANHO 10;

// Struct NoPilha* --> PtrNoPilha ---- Definir Tipo
typedef struct  NoPilha* PtrNoPilha;

// NoPilha
typedef struct NoPilha{
    // Chave (Informação)
    char x;

    // Referência interna do próximo elemento (*NoPilha)
    PtrNoPilha proximo;
} NoPilha;

// Pilha dinamica
typedef struct {
    int tamanho;
    PtrNoPilha topo;
} PilhaDinamica;

/****************************************************
 * Operações * 
 * ***************************************************/

// Iniciar a pilha
void iniciarPilhaDinamica(PilhaDinamica *pilha){
    pilha->tamanho;
    pilha->topo = NULL;
    // Inicio
    // f->primeiro = NULL;
    // Fim
    // f->ultimo = NULL;
    // Quantidade de elementos
    // f->contadorElementos = 0;
}

// estaVazia
bool estaVaziaPilhaDinamica(PilhaDinamica *pilha){
    return (pilha->tamanho == 0);
}

// Tamanho
int tamanhoPilhaDinamica(PilhaDinamica *pilha){
    return (pilha->tamanho);
}

// Imprime pilha
// void printPilhaDinamica(PilhaDinamica *f){
//     printf("Pilha dinamica = [");
//     // Quantidade
//     // Tudo que é != NULL
//     PtrNoPilha percorre;

//     for (percorre = f->topo; percorre != NULL; percorre = percorre->proximo){
//         printf("%d ", percorre->chave);
//     }    
//     printf("]\n");
// }

// Inserir (Passar uma pilha, e o valor a ser inserido) -> Deve ser inserido no final da pilha
void enfileirarPilhaDinamica(PilhaDinamica *pilha, int x){
    PtrNoPilha aux;

    // Criando bloco
    aux = (PtrNoPilha)malloc(sizeof(NoPilha));

    // Copiando o valor pra dentro do no alocado (auxiliar)
    aux->x = x;

    // Novo = proximo aponta p topo
    aux->proximo = pilha->topo;

    // Topo -> novo topo
    pilha->topo = aux;

    pilha->tamanho++;
}

// Desempilha elementos
void desempilharPilhaDinamica(PilhaDinamica *pilha){
    //Valor de retorno

    if (!estaVaziaPilhaDinamica(pilha)){
        PtrNoPilha aux = pilha->topo;

        pilha->topo = pilha->topo->proximo;

        // Desalocando a memória
        free(aux);

        // Decrementa a quantidade da pilha
        pilha->tamanho--;
    } else {
        printf("Warning: pilha está vazia!\n");
    }
}


// Destrói pilha
void destruirFilhaDinamica(PilhaDinamica *pilha){
    while (!estaVaziaPilhaDinamica(pilha)){
        desempilharPilhaDinamica(pilha);
    }

    if (estaVaziaPilhaDinamica(pilha)){
        free(pilha);
    }
}

// Função de notação
void resolve(PilhaDinamica *p, char operador, int posicaoAtual, int ultimo, FILE* saida, int* contadorF){
    // Contador - variável TEMP
    int contador = *contadorF;

    char op1, op2, temp1, x;

    // Atribuindo o topo da pilha à variável e imprimindo no arquivo qual variável foi desempilhada
    op1 = p->topo->x;

    if (op1 >= 49 && op1 <= 57){
        printf("LDR TEMP%c\n", op1);
    } else {
        printf("LDS %c\n", op1);
        fprintf(saida, "LDR %c\n", op1);
    }

    desempilharPilhaDinamica(p);
    
    // op2
    op2 = p->topo->x;

    if (op2 >= 49 && op2 <= 57){
        printf("LDR TEMP%c\n",op2);
    	fprintf(saida,"LDR TEMP%c\n",op2);
    } else {
        printf("LDR %c\n", op2);
        fprintf(saida, "LDR %c\n", op2);
    }

    desempilharPilhaDinamica(p);

    // Verificando qual operador foi encontrado no arq. de entrada
    switch (operador){
            case '+':
                // Incrementa contador de TEMP
                contador++;
                *contadorF = *contadorF + 1;

                // Casos para impressão no arquivo de saída dependendo do tipo(caractere ou TEMP) e da ordem das variáveis
                if ((op2 >= 49 && op2 <=57) && (op1 >= 49 && op1 <= 57)){
                    printf("ADD TEMP%c TEMP%c\n", op1, op2);

                    fprintf(saida, "ADD TEMP %c %c\n", op1, op2);
                } else if (op1 >= 49 && op1 <= 57){
                    printf("ADD TEMP%c %c\n", op1, op2);

                    fprintf(saida, "ADD TEMP%c %c\n", op1, op2);
                } else if (op2 >= 49 && op2 <= 57){
                    printf("ADD %c TEMP%c\n",op1,op2);

                    fprintf(saida,"ADD %c TEMP%c\n",op1,op2);
                } else {
                    printf("ADD %c %c\n",op1, op2);

                    fprintf(saida,"ADD %c %c\n",op1, op2);
                }

            // Se não for a última opção, empilhar o resultado da operação
            // e imprimir no arquivo de saida
            if (posicaoAtual != ultimo){
                x = '0' + contador;

                printf("STR TEMP%d\n", contador);

                fprintf(saida, "STR TEMP%d\n", contador);

                enfileirarPilhaDinamica(p, x);
            }
            break;

        case '-':
            // Incrementa o variável TEMP
            contador++;
            *contadorF = *contadorF + 1;

            // Casos p impressão no arq de saída dependependo do tipo - caractere ou TEMP - e da ordem
            if ((op2 >= 49 && op2 <= 57) && (op1 >= 49 && op2 <= 57)){
                printf("SUB TEMP%c TEMP%c\n", op1, op2);

                fprintf(saida,"SUB TEMP%c TEMP%c\n",op1, op2);
            } else if (op1 >= 49 && op1 <= 57){
                printf("SUB TEMP%c %c\n",op1, op2);
                
                fprintf(saida,"SUB TEMP%c %c\n",op1, op2);
            } else if (op2 >= 49 && op2 <= 57){
                printf("SUB %c TEMP%c\n",op1 ,op2);
                
                fprintf(saida,"SUB %c TEMP%c\n",op1, op2);
            } else {
                printf("SUB %c %c\n",op1, op2);

                fprintf(saida,"SUB %c %c\n",op1, op2);
            }

        if (posicaoAtual != ultimo){
            x = '0' + contador;
            printf("STR TEMP%d\n", contador);

            fprintf(saida, "STR TEMP%d", contador);
            enfileirarPilhaDinamica(p, x);
        }

        break;

        case '*':
            // Incrementa a variável TEMP
            contador++;

            *contadorF = *contadorF + 1;

            // Casos p impressão no arq. de saída dependendo do tipo - caractere ou TEMP
            if ((op2 >= 49 && op2 <= 57) && (op1 >= 49 && op1 <= 57)){
                printf("MUL TEMP%c TEMP%c\n",op1, op2);

		        fprintf(saida,"MUL TEMP%c TEMP%c\n",op1, op2);
            } else if (op1 >= 49 && op1 <= 57){
                printf("MUL TEMP%c %c\n",op1, op2);

		        fprintf(saida,"MUL TEMP%c %c\n",op1, op2);
            } else if (op2 >= 49 && op2 <= 57){
                printf("MUL %c TEMP%c\n",op1, op2);
		        fprintf(saida,"MUL %c TEMP%c\n", op1, op2);
            } else {
                printf("MUL %c %c\n",op1, op2 );
		        fprintf(saida,"MUL %c %c\n", op1, op2 );
            }

            
            // Caso não seja a última operação, empilhar o resultado da operação e imprimir no arquivo de saída 
            if (posicaoAtual != ultimo){
                x = '0' + contador;

                fprintf(saida, "STR TEMP%d\n", contador);

                enfileirarPilhaDinamica(p, x);
            }
            break;

        case '/':
            // Incrementa a variável TEMP
            contador++;

            *contadorF = *contadorF + 1;

            // Casos p impressão no arquivo de saída dependendo do tipo
            if ((op2 >= 49 && op2<=57) && (op1 >= 49 && op1<=57)){
                printf("DIV TEMP%c TEMP%c\n", op1, op2);

                fprintf(saida,"DIV TEMP%c TEMP%c\n", op1, op2);
            } else if (op1 >= 49 && op1 <= 57){
                printf("DIV TEMP%c %c\n", op1, op2);
		    	
                fprintf(saida,"DIV TEMP%c %c\n", op1, op2);
            } else if (op2 >= 49 && op2 <= 57){
                printf("DIV %c TEMP%c\n", op1, op2);
		    	
                fprintf(saida,"DIV %c TEMP%c\n", op1, op2);
            } else {
                printf("DIV %c %c\n", op1, op2);

		    	fprintf(saida,"DIV %c %c\n", op1, op2);
            }

            // Caso não seja a última operação, empilhar o resultado da operação e imprimir no arquivo de saída 
            if (posicaoAtual != ultimo){
                x = '0' + contador;

                fprintf(saida, "STR TEMP%d\n", contador);

                enfileirarPilhaDinamica(p, x);
            }
            break;
    }
}

/****************************************************/

int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese"); // Definição para uso de caracteres especiais

    int contador = 0;

    // Verificando os parâmetro argc e argv
    if (argc != 3){
        printf("Quantidade parametros invalida!\n");

        return 1;
    }

    /* Acessando arquivos */
    FILE *ArqEntrada = fopen(argv[1], "r");
    FILE *ArqSaida = fopen(argv[2], "w");

    // Inicializando a pilha
    PilhaDinamica pilhacompilador;
    iniciarPilhaDinamica(&pilhacompilador);

    char c;
    int tamanho = -1;

    while ((c = fgetc(ArqEntrada)) != EOF){
        tamanho++;

        if (tamanho == 1){
            if (!(c >= 65 && c <= 90)){
                printf("Expressão inválida!\n");

                fprintf(ArqSaida, "Expressão inválida!\n");

                return 1;
            }
        }

        // Verificando existência de quebra de linha no arquivo de entrada
        if (c == '\n'){
            tamanho--;
        }
    }

    // Retornando o indicador de posição para o começo
    rewind(ArqEntrada);

    int atual = -1;

    // Lendo o arquivo de entrada até o final
    while ((c = fgetc(ArqEntrada)) != EOF){
        // Contador de caracteres já lidos do arquivo de entrada
        atual++;

        // Verifica se o caractere lido é um operador enviado p resolver a notação pós
        if (c == '+' || c == '-' || c == '*' || c == '/'){
            resolve(&pilhacompilador, c, atual, tamanho, ArqSaida, &contador);
        }

        // Verifica se há quebra de linha no arquivo
        if (c == '\n'){
            tamanho--;
        }
    }

    fclose(ArqEntrada);
    fclose(ArqSaida);

    destruirFilhaDinamica(&pilhacompilador);  

    return 0;
}