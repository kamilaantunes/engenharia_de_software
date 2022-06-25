#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct NoLista* PtrNoLista;

typedef struct NoLista{
    int pag;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista primeiro;
    int tamanho;
} Lista;

typedef struct NoArvore *PtrNoArvore;

typedef struct Objeto{
    char termo[30];
    Lista paginas;
} Objeto;

typedef struct NoArvore{
    Objeto obj;
    PtrNoArvore filhoDireita;
    PtrNoArvore filhoEsquerda;
} NoArvore;


// Funções para manipulação da lista
void iniciaLista(Lista *lista){
    lista->primeiro = NULL;
    lista->tamanho = 0;
}

bool listaEstaVazia(Lista *lista){
    return (
        lista->tamanho == 0
    );
}

bool pesquisarLista(Lista *lista, int key){
    if (listaEstaVazia(lista)){
        return false;
    }

    PtrNoLista percorre;

    for (percorre = lista->primeiro; percorre != NULL; percorre = percorre->proximo){
        if (percorre->pag == key){
            return true;
        }
    }

    return false;
}

void inserirLista(Lista *lista, int x){
    PtrNoLista aux;
    // Criação e alocação do ponteiro novo
    PtrNoLista novo;
    novo = (PtrNoLista)malloc(sizeof(NoLista));
    novo->pag = x;

    // Situação 1: Se a lista vazia ou o elemento que queremos inserir é menor que o primeiro
    if (listaEstaVazia(lista) || x < lista->primeiro->pag){
        novo->proximo = lista->primeiro;
        lista->primeiro = novo;
    } else { // Situação 2: Aux percorre a lista para encontrar o ponto de inserção
        aux = lista->primeiro;

        while (aux->proximo != NULL && x > aux->proximo->pag){
            aux = aux->proximo;
        }

        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    
    lista->tamanho++;
}


// Funções para manipulaçãoda árvore
void iniciaArvore(PtrNoArvore *tree){
    *tree = NULL;
}

bool insereArvore(PtrNoArvore *tree, char *termo){
    // Caso 1: Encontrou o ponto de inserção
    if (*tree == NULL){
        // Novo nó
        (*tree) = malloc(sizeof(NoArvore));

        // Filho da direita e filha da esquerda = NULL
        (*tree)->filhoDireita = NULL;
        (*tree)->filhoEsquerda = NULL;

        // Atribuindo o termo ao nó
        strcpy ((*tree)->obj.termo, termo);
        iniciaLista(&(*tree)->obj.paginas);

        return true;
    }

    if (strcmp((*tree)->obj.termo, termo) == 0){
        return false;
    }

    // Caso 3
    if (strcmp((*tree)->obj.termo, termo) > 0){
        return (
            insereArvore (&(*tree)->filhoEsquerda, termo)
        );
    } else {
        return (
            insereArvore(&(*tree)->filhoDireita, termo)
        );
    }
}

bool procurar(PtrNoArvore *tree, char *palavra, int pag){
    // Caso 1: Não achou o elemento ou não exista na árvore
    if (*tree == NULL) {
        return (
            false
        );
    }

    // Caso 2: Nó cujo valor é o procurado
    if (strcmp((*tree)->obj.termo, palavra) == 0 && !pesquisarLista(&(*tree)->obj.paginas, pag)){
        inserirLista(&(*tree)->obj.paginas, pag);

        return (
            true
        );
    }

    if (strcmp((*tree)->obj.termo, palavra) > 0){
        return (
            procurar(&(*tree)->filhoEsquerda, palavra, pag)
        );
    } else {
        return (
            procurar(&(*tree)->filhoDireita, palavra, pag)
        );
    }
}

bool estaVazia(PtrNoArvore *tree){
    return (
        *tree == NULL
    );
}

void emOrdem(PtrNoArvore *node, FILE *arqSaida){
    // Percorrer a arvore na ordem alfabética dos termos
    PtrNoLista percorre;

    if (*node == NULL) {
        return;
    }

    emOrdem (&(*node)->filhoEsquerda, arqSaida);
    fprintf(arqSaida, "%s", (*node)->obj.termo);

    for (percorre = (*node)->obj.paginas.primeiro; percorre != NULL; percorre = percorre->proximo){
        fprintf(arqSaida, ",%d", percorre->pag);
    }

    fprintf(arqSaida, "\n");
    emOrdem(&(*node)->filhoDireita, arqSaida);
}

void destroiArvore(PtrNoArvore *node){
    // Percorrer a árvore e desalocar memória de trás para frente
    if ((*node) != NULL){
        destroiArvore(&(*node)->filhoEsquerda);
        destroiArvore(&(*node)->filhoDireita);

        free(*node);
        (*node) = NULL;
    }
}

int main(int argc, const char * argv[]){
    char *palavra;
    char linha1[100];
    char texto[300];
    int pag = 0;

    PtrNoArvore raiz;
    iniciaArvore(&raiz);

    if (argc != 3){
        printf("Número de parametros nao é o correto!\n");
        exit(1);
    }

    FILE *arqEntrada = fopen(argv[1], "r");
    FILE *arqSaida = fopen(argv[2], "w");

    // Tratamento de erros de abertura dos arquivos
    if (arqEntrada == NULL){
        printf("Erro ao abrir o arquivo de entrada!\n");
        exit(1);
    }

    if (arqSaida == NULL){
        printf("Erro ao abrir o arquivo de saída!\n");
        exit(1);
    }

    if (fscanf(arqEntrada, "%s[^\n]", &linha1) == -1){
        printf("Arquivo de entrada vazio!\n");
        fprintf(arqSaida, "Arquivo de entrada vazio!\n");
        
        exit(1);
    }

    strlwr(linha1);

    palavra = strtok(linha1, " .()<:,>\n");

    if (strcmp(palavra, "termos") != 0 && strcmp(palavra, "termo") != 0){
        printf("Arquivo de entrada no formato errado!\n");
        fprintf(arqSaida, "Arquivo de entrada no formato errado!\n");

        exit(1);
    } else {
        palavra = strtok(NULL, " .()<:,>\n");

        while (palavra != NULL){
            // Inserir na árvore
            insereArvore(&raiz, palavra);
            palavra = strtok(NULL, " .()<:,>\n");
        }
    }

    while (fgets(texto, 299, arqEntrada) != NULL){
        while (texto);

        palavra = strtok(texto, " .()<:,>\n");

        while (palavra != NULL){
            if (strcmp(palavra, "page") == 0){
                pag++;
            } else {
                // Procurando a palavra
                procurar(&raiz, palavra, pag);
            }
            palavra = strtok(NULL, " .()<:,>");
        }
    }

    // Imprimir os termos em ordem alfabética
    emOrdem(&raiz, arqSaida);
    printf("Arquivo de saida criado com sucesso!\n");

    destroiArvore(&raiz);
    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;
}