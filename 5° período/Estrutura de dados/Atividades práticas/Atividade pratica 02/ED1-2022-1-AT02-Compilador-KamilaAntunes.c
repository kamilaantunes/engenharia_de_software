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
    int chave;

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
void iniciarPilhaDinamica(PilhaDinamica *f){
    f->tamanho;
    f->topo = NULL;
    // Inicio
    // f->primeiro = NULL;
    // Fim
    // f->ultimo = NULL;
    // Quantidade de elementos
    // f->contadorElementos = 0;
}

// estaVazia
bool estaVaziaPilhaDinamica(PilhaDinamica *f){
    return (f->tamanho == NULL);
}

// Tamanho
int tamanhoPilhaDinamica(PilhaDinamica *f){
    return (f->tamanho);
}

// Imprime pilha
void printPilhaDinamica(PilhaDinamica *f){
    printf("Pilha dinamica = [");
    // Quantidade
    // Tudo que é != NULL
    PtrNoPilha percorre;

    for (percorre = f->topo; percorre != NULL; percorre = percorre->proximo){
        printf("%d ", percorre->chave);
    }    
    printf("]\n");
}

// Inserir (Passar uma pilha, e o valor a ser inserido) -> Deve ser inserido no final da pilha
void enfileirarPilhaDinamica(PilhaDinamica *f, int valor){
    PtrNoPilha aux;

    // Criando bloco
    aux = (PtrNoPilha)malloc(sizeof(PtrNoPilha));

    // Copiando o valor pra dentro do no alocado (auxiliar)
    aux->chave = valor;

    // Novo = proximo aponta p topo
    aux->proximo = f->topo;

    // Topo -> novo topo
    f->topo = aux;

    f->tamanho++;
}

// Desempilha elementos
int desempilharElemento(PilhaDinamica *f){
    //Valor de retorno
    int ret = -99;

    if (!estaVaziaPilhaDinamica(f)){
        PtrNoPilha aux;

        aux = f->topo;
        ret = aux->chave;

        f->topo = aux->proximo;

        // Desalocando a memória
        free(aux);

        // Decrementa a quantidade da pilha
        f->tamanho--;
    } else {
        printf("Warning: pilha está vazia!\n");
    }

    // Retornando o valor da pilha
    return(ret);
}


// Destrói pilha
void destruirFilhaDinamica(PilhaDinamica *f){
    PtrNoPilha remover;

    while (f->topo != NULL){
        remover = f->topo;
        f->topo = f->topo->proximo;

        free(remover);
    }
}

/****************************************************/


int main(int argc, char *argv[]){
    setlocale(LC_ALL, "Portuguese"); // Definição para uso de caracteres especiais

    /* Declarações */
    int i;
    PilhaDinamica pilha;
    // char s;

    iniciarPilhaDinamica(&pilha);

    /* Acessando arquivos */
    FILE *ArqEntrada = fopen("entrada01.txt", "r");
    // FILE *ArqAux = fopen(argv[1], "r");
    FILE *ArqSaida = fopen("saida01.txt", "w");

    // printf("Saída: %s", argv[2]);

    // Validando o arquivo de entrada
    if (ArqEntrada == NULL){
        printf("Erro! O arquivo de entrada não pode ser acessado.\n");

        system("pause");
        return(0);
    } else {
        printf("Arquivo acessado com sucesso!\n");
    }

    // Validando o arquivo de saída
    if (ArqSaida == NULL){
        printf("Erro! O arquivo de saída não pode ser criado!\n");

        system("pause");
        return(0);
    } else {
        printf("Arquivo criado com sucesso!\n");
    }

    int str;
    while (true) {
        if (str >= 'a' && str <= 'z'){
            fscanf(ArqEntrada, "%d", &str);
        } else {
            if (str == '+' || str == '-' || str == '*' || str == '/' || str || '^') {
                fscanf(ArqEntrada, "%d", &str);
            }
        }

        if (feof(ArqEntrada)){
            break;
        }
    }
    

    // if (estaVaziaPilhaDinamica(&pilha)){
    //     printf ("A pilha está vazia!\n");
    // }

    // int tam = tamanhoPilhaDinamica(&Pilha);
    // printf("O tamanho da pilha é = %d\n", tam);
    // printPilhaDinamica(&Pilha);

    // Inserir
    // printf("--------------------------------\n");
    // int inserir[] = {1, 2, 3, 4};
    // for (i = 0; i < 3; i++){
    //     enfileirarPilhaDinamica(&pilha, inserir[i]);
    //     printPilhaDinamica(&pilha);
    // }


    printf("--------------------------------\n");
    // Remover
    // char str;

    // for (i = 0; i < 3; i++){
    //     desenfileirarPilhaDinamica(&pilha);
    //     printf("Elemento removido: %c", str);

    //     printPilhaDinamica(&pilha);
    // }

    // printf("Ta funfando!");

    destruirFilhaDinamica(&pilha);

    fclose(ArqEntrada);
    fclose(ArqSaida);

    return 0;
}