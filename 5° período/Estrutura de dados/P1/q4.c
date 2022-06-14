/* Descrição da atividade:
 * Implemente uma função que receba um vetor de valores inteiros com n elementos e construa uma lista encadeada armazenando os elementos do vetor
 * nos nós da lista. Se o vetor tiver zero elementos, a função deve ter como valor de retorno uma lista vazia. O protótipo da função é dado por:
 * Lista* constroi(int n, int* v);
 * Obs: elabore sua função e a testa em um arquivo único contendo a main. Realize o upload deste arquivo aqui, depois de realizar os testes na sua máquina.
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

#include"function.h"

typedef struct lista{
    int info;
    struct lista *prox;
} Lista;

Lista* criarLista(){
    return NULL;
}

Lista* inserirLista(Lista *L, int i){
    Lista *novo, *p = L;
    novo = (Lista*)malloc(sizeof(Lista));

    novo->info = i;
    novo->prox = NULL;

    if (p == NULL){
        return novo;
    } else {
        while (p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;

        return L;
    }
}

void liberarLista(Lista *L){
    Lista * p = L;

    while (p != NULL){
        Lista* t = p->prox;

        free(p);

        p = t;
    }
    
}

void imprimirLista(Lista *L){
    Lista *p = L;

    if (p == NULL){
        printf("Lista vazia!\n");
    } else {
            printf("Lista para receber vetor: ");
            
            while (p != NULL){
            printf("%d ", p->info);

            p = p->prox;
        }
    }
}

Lista* constroi(int *v, int n){
    Lista* listaV;
    listaV = criarLista();

    int i;

    // Lista *listaV = NULL;

    for (i = 0; i < n; i++){
        // L2 = inserirLista(L2, v[i]);
        Lista* novo = (Lista*)malloc(sizeof(Lista));

        Lista* p = listaV;

        novo->info = v[i];
        novo->prox = listaV;

        if (p == NULL){
            listaV = novo;
        } else {
            while (p->prox != NULL){
                p = p->prox;
            }
            p->prox = novo;
            novo->prox = NULL;            
        }
    }
    return listaV;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int n, i;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    printf("\n");

    vetor = (int*)malloc(n*sizeof(int));

    for (i = 0; i < n; i++){
        printf("Valor da posição [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    printf("\n");

    // Teste de impressão
    for (i = 0; i < n; i++){
        printf("Valor da posicao [%d]: %d\n", i, vetor[i]);
    }
    
    printf("\n");

    Lista* listaVetor;

    // printf("Lista com valores do vetor: ");
    listaVetor = constroi(vetor, n);

    imprimirLista(listaVetor);

    printf("\n");

    liberarLista(listaVetor);

    return 0;



    // Lista *listaV = NULL;
    // int v[] = {2, 4, 10, 13, 15};

    // listaV = constroi(5, v);

    // imprimirLista(listaV);
    // liberarLista(listaV);
}