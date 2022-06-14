#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include<locale.h>

#define TamNome 100

/******************************************************************************************************************************************************************************/

// Lista Ordenada
typedef struct NoLista * ptrNoLista;

typedef struct NoLista{
    int cod;
    char nome[TamNome];
    char sexo;
    int idade;
    float peso;
    int altura;
    int telefone;

    ptrNoLista proximo;
    ptrNoLista anterior;
}NoLista;

typedef struct {
    ptrNoLista inicio;
    ptrNoLista fim;
}ListaOrdenada;

/******************************************************************************************************************************************************************************/
// Implementação da lista ordenada

// Inicializando a lista ordenada
void iniciaLista(ListaOrdenada *l){
    l->inicio = l->fim = NULL;
}

// Verificando se a lista está vazia
bool verificaListaVazia(ListaOrdenada *l){
    return (l->inicio == NULL);
}

// Inserido elementos/nós na lista
void insereElementosLista(ListaOrdenada *l, int cod, char *nome, char sexo, int idade, float peso, int altura, int telefone){

    ptrNoLista no = malloc(sizeof(NoLista));

    // Atribuindo valores para o nó
    no->cod = cod;
    strcpy(no->nome, nome);
    no->sexo = sexo;
    no->idade = idade;
    no->peso = peso;
    no->altura = altura;
    no->telefone = telefone;

    // Caso 1: Se a lista estiver vazia
    if (verificaListaVazia(l)){

    // O próximo do nó é o inicio (próximo do nó = NULL)
    no->proximo = l->inicio;
    
    // O anterior do nó é o fim (anterior do nó = NULL)
    no->anterior = l->fim;
    
    // O inicio armazena o nó
    l->inicio = no;
    
    // O fim armazena o nó
    l->fim = no;

  } else if (cod <= l->inicio->cod){ // Caso 2: Se o elemento se torne o primeiro da lista

    // O próximo do nó é o inicio
    no->proximo = l->inicio;
    
    // O nó não possui anterior logo é igual a nulo (anterior do nó = NULL)
    no->anterior = NULL;
    
    // O anterior do próximo nó é o nó
    no->proximo->anterior = no;
    
    // O inicio armazena o nó
    l->inicio = no;

  } else { // Caso3: Caso esteja posicionado no meio da lista

    ptrNoLista percorre = l->inicio;

    // Procura a posição correta para armazenar o nó
    while (percorre->proximo != NULL && cod > percorre->proximo->cod){
        percorre = percorre->proximo;
    }

    // O proximo aponta para o próximo do percorre
    no->proximo = percorre->proximo;
    
    // O anterior do nó aponta para percorre
    no->anterior = percorre;
    
    // O próximo do percorre aponta para o nó
    percorre->proximo = no;

    // Verificando se o próximo do nó não é nulo, para poder atribuir o anterior do próximo nó
    if (no->proximo == NULL){
        l->fim = no;
    } else {
        no->proximo->anterior = no;
    }

  }

}

// Imprimindo os dados em forma crescente de acordo com codigo
void imprimeCrescente(ListaOrdenada *l, FILE *saida){

    ptrNoLista percorre = l->inicio;

    while (percorre != NULL){
        fprintf(saida, "{%i,%s,%c,%d, %.1f, %d, ,%d}\n", percorre->cod, percorre->nome, percorre->sexo, percorre->idade, percorre->altura, percorre->telefone);
        percorre = percorre->proximo;
    }

}

// Imprimindo os dados em forma descrescente de acordo com codigo
void imprimeDescrescente(ListaOrdenada *l, FILE *saida){

    ptrNoLista percorre = l->fim;

    while(percorre != NULL){
        fprintf(saida, "{%i,%s,%c,%d, %.1f, %d, ,%d}\n", percorre->cod, percorre->nome, percorre->sexo, percorre->idade, percorre->peso, percorre->altura, percorre->telefone);
        percorre = percorre->anterior;
    }
}

// Pesquisando o codigo e retornando as informações do codigo (nome, sexo, idade, peso, altura, telefone)
bool pesquisaCod(ListaOrdenada *l, int cod, FILE *saida){

    // Verificando se a lista está vazia e le o codigo é valido
    if (verificaListaVazia(l) || cod < l->inicio->cod){
        fprintf(saida, "Elemento não encontrado!\n");
    
        return false;
    }

    // Verificando se o codigo é o primeiro da lista
    if (cod == l->inicio->cod){
        fprintf(saida, "{%i,%s,%c,%d, %.1f, %d, ,%d}\n", l->inicio->cod, l->inicio->nome, l->inicio->sexo, l->inicio->idade, l->inicio->peso, l->inicio->altura, l->inicio->telefone);
    
        return true;
    }

    ptrNoLista percorre = l->inicio;

    // Procurando o codigo na lista
    while (percorre != NULL && cod > percorre->cod){
        percorre = percorre->proximo;
    }

    // Verificando se o codigo está correto
    if (percorre == NULL || cod != percorre->cod){
        fprintf(saida, "Elemento não encontrado!\n\n");
    
        return false;
    }

    fprintf(saida, "{%i,%s,%c,%d, %.1f, %d, ,%d}\n", percorre->cod, percorre->nome, percorre->sexo, percorre->idade, percorre->peso, percorre->altura, percorre->telefone);
    return true;

}

// Destroindo a lista ordenada
void destroiLista(ListaOrdenada *l){

    ptrNoLista percorre = l->inicio;
    ptrNoLista aux;

    // Percorrendo os nós
    while(percorre != NULL){
    
        // Destroindo os nós
        aux = percorre;
        free(aux);
    
        // Percorre recebe o próximo nó
        percorre = percorre->proximo;
    }

    // Resetando o inicio e fim
    l->inicio = NULL;
    l->fim = NULL;

}

/******************************************************************************************************************************************************************************/
// Lendo o arquivo de entrada
char leituraArquivo(ListaOrdenada *l, FILE *entrada){

    NoLista le;
    char caractere, c;

    while ((caractere = fgetc(entrada)) == '{'){

        // Leitura do codigo
        fscanf(entrada, "%i,", &le.cod);

        memset(le.nome, 0,sizeof(le.nome));

        // Leitura do nome do paciente
        for (int i = 0; i < TamNome; i++){
            c = fgetc(entrada);

            if (c != ','){
                le.nome[i] = c;
            } else {
                break;
            }
        }

        //Leitura do sexo, idade, peso, altura e telefone
        fscanf(entrada, "%c,%d,%.1f, %d, %d}\n", &le.sexo, &le.idade, &le.peso, &le.altura, &le.telefone);

        //Inserindo os valores na lista
        insereElementosLista(l, le.cod, le.nome, le.sexo, le.idade, le.peso, le.altura, le.telefone);
    }

    return caractere;

}

/******************************************************************************************************************************************************************************/

int main(int argc, const char * argv[]){
    setlocale(LC_ALL, "Portuguese"); // Definição para uso de caracteres especiais

    FILE *entrada, *saida;
    char c;
    int cod;

    if (argc != 3){
        printf("Erro: os parâmetros foram informados incorretamente!\nFechando Programa\n\n");
        exit(1);
    } else {
        entrada = fopen(argv[1], "r");
        saida = fopen(argv[2], "w");


        if (entrada == NULL || saida == NULL){
            printf("Erro: ocorreu um problema ao abrir os arquivos!\nFechando o programa\n");
      
            exit(1);
        }
    }

    ListaOrdenada lista;
    iniciaLista(&lista);

    c = leituraArquivo(&lista, entrada);

    switch(c){

        case '1':
            imprimeCrescente(&lista, saida);
            break;

        case '2':
            imprimeDescrescente(&lista, saida);
            break;

        case '3':
            fscanf(entrada, "%i", &cod);
            pesquisaCod(&lista, cod, saida);
            break;

        default:
            fprintf(saida, "Arquivo Inválido");
            break;
    }

    destroiLista(&lista);

    return 0;
}