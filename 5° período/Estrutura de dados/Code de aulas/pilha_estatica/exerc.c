// #include<stdio.h>
// #include<stdbool.h>
// #define TAMANHO 6

// /*************************************************/

// // TAD - Pilha estatica
// typedef struct {
//     // vetor - int
//     int vetor[TAMANHO];
//     // topo (int) - indexador -> guarda o indíce de posições do vetor
//     int topo;
// } PilhaEstatica;

// // Operações

// /* Inicialização */
// void inicializarPilhaEstatica(PilhaEstatica *p){
//     p->topo = 0;
// }

// // estaVazia?
// bool estaVaziaPilhaEstatica(PilhaEstatica *p){
//     return (p->topo == 0);
// }

// // estaCheia?
// bool estaCheiaPilhaEstatica(PilhaEstatica *p){
//     return(p->topo == TAMANHO);
// }

// // tamanho
// int tamanhoPilhaEstatica(PilhaEstatica *p){
//     return(p->topo);
// }

// // impressão - print
// void imprimirPilhaEstatica(PilhaEstatica *p){
//     printf("Pilha = [");
//     for (init i = 0; i < p->topo; i++){
//         printf("%d", p->vetor[i]);
//     }
//     printf("]\n");
// }

// // * inserção - empilha - push
// void empilharPilhaEstatica(PilhaEstatica *pilha, int x){
//     // se a pilha não estiver cheia:
//     if (!estaCheiaPilhaEstatica(pilha)){
//         // adicionar o numero x na posição indezada pelo topo
//         pilha->topo[pilha->topo] = x;
//         // incremeta o valor do topo
//         pilha->topo++;
//     } else {
//         printf("Warning: Pilha cheia!\n");
//     }
// }

// // remocao - desempilha - pop
// void desempilharPilhaEstatica(PilhaEstatica *pilha){
//     // se a pilha não esta vazia:
//     if (!estaVaziaPilhaEstatica(pilha)){
//         // (opcional): copiar o valor do vetor[topo] em um aux
//         // topo decrementado retornar uma posição
//         pilha->topo--
//         // (opcional): retorna o elemento aux
//     } else {
//         printf("Warning: Pilha está vazia!\n");
//     }
// }

// // consulta - topo, sem remover
// int topoPilhaEstatica(PilhaEstatica *pilha){
//     int ret = pilha->vetor[pilha->topo-1];
//     return(ret);
// }

// /*************************************************/

// int main(int argc, const char * argv[]) {
//     PilhaEstatica pilha;
//     inicializarPilhaEstatica(&pilha);

//     if(estaVaziaPilhaEstatica(&pilha)){
//         printf("Pilha está vazia!\n");
//     }

//     if (!estaCheiaPilhaEstatica(&pilha)){
//         printf("Pilha não está cheia. Podemos inserir elementos.\n");
//     }

//     int tam = tamanhoPilhaEstatica(&pilha);
//     printf("Tamanho da pilha = %d\n", tam);
//     imprimirPilhaEstatica(&pilha);

//     int insercao[] = {02, 04, 10, 13, 15, 23, 31};
//     int top;

//     for (int k = 0; k < 7; k++){
//         empilharPilhaEstatica(&pilha, insercao[k]);
//         imprimirPilhaEstatica(&pilha);
//         top = topoPilhaEstatica(&pilha);
        
//             printf("Topo: %d\n", top);

//         tam = tamanhoPilhaEstatica(&pilha);

//             printf("Tamanho da pilha = %d\n", tam);
//             printf("/--------------------------------------------/\n");
//     }

//     for (int i = 0; i < tam; i++){
//         desempilharPilhaEstatica(&pilha);
//         imprimirPilhaEstatica(&pilha);
//     }

//     empilharPilhaEstatica(&pilha, 42);
//     imprimirPilhaEstatica(&pilha);

//     return 0;
// }

#include <stdio.h>
#include <stdbool.h> // true/false
#define TAMANHO 6

//-----------------------
//-----------------------

// TAD (Pilha Estatica)
typedef struct {
  // vetor (int)
  int vetor[TAMANHO];
  // topo (int) - indexador (guarda o indice de posicoes do vetor)
  int topo;
} PilhaEstatica;

//-----------------------
// Operações
//-----------------------

// inicializacao
void inicializarPilhaEstatica(PilhaEstatica *p) { //&pilha
  p->topo = 0;
}

// estavazia
bool estaVaziaPilhaEstatica(PilhaEstatica *p) {
  return(p->topo == 0);
}

// estaCheia
bool estaCheiaPilhaEstatica(PilhaEstatica *p) {
  return(p->topo == TAMANHO);
}

// tamanho
int tamanhoPilhaEstatica(PilhaEstatica *p) {
  return(p->topo);
}

// impressao (print)
void imprimirPilhaEstatica(PilhaEstatica *p) {
  printf("Pilha = [");
  for(int i = 0; i < p->topo; i++) {
    printf("%d ", p->vetor[i]);
  }
  printf("]\n");
}

// * insercao (empilha/push)
void empilharPilhaEstatica(PilhaEstatica *pilha, int x) {
// se a pilha nao estiver cheia:
  if(!estaCheiaPilhaEstatica(pilha)) {
    //     add o numero (x) na posicao indexada pelo topo
    pilha->vetor[pilha->topo] = x;
    //     incrementa o valor do topo
    pilha->topo++;
  } else {
    printf("Warning: pilha cheia!\n");
  }
}

// remocao (desempilha/pop)
void desempilharPilhaEstatica(PilhaEstatica *pilha) {
  // se a pilha nao esta vazia:
  if(!estaVaziaPilhaEstatica(pilha)){
    // (opcional): copiar o valor do vetor[topo] em um aux
    // topo decrementado retornar uma posicao
    pilha->topo--;
    // (opcional): retorna o elemento aux
  } else {
    printf("Warning: pilha está vazia!\n");
  }
}

// consulta (topo)
int topoPilhaEstatica(PilhaEstatica *pilha) {
  int ret = pilha->vetor[pilha->topo-1];
  return(ret);
}

//-----------------------
//-----------------------

int main(int argc, const char * argv[]) {

  PilhaEstatica pilha;
  inicializarPilhaEstatica(&pilha);
  if(estaVaziaPilhaEstatica(&pilha)) {
    printf("Pilha está vazia\n");
  }

  if(!estaCheiaPilhaEstatica(&pilha)) {
    printf("Não está cheia. podemos add elementos\n");
  }

  int tam = tamanhoPilhaEstatica(&pilha);
  printf("Tamanho da pilha = %d\n", tam);
  imprimirPilhaEstatica(&pilha);      // Pilha = []

  int insercao[] = {44, 26, 20, 777, 83, 58, 42};
  int top;

  for(int k = 0; k < 7; k++){
    empilharPilhaEstatica(&pilha, insercao[k]);
    imprimirPilhaEstatica(&pilha);
    top = topoPilhaEstatica(&pilha);
    printf("Topo = %d\n", top);
    tam = tamanhoPilhaEstatica(&pilha);
    printf("Tamanho da pilha = %d\n", tam);
    printf("----------------------\n");
  }

  for(int i = 0; i < tam + 1; i++) {
    desempilharPilhaEstatica(&pilha);
    imprimirPilhaEstatica(&pilha);
  }
  empilharPilhaEstatica(&pilha, 42);
  imprimirPilhaEstatica(&pilha);

  return 0;
}

//-----------------------
//-----------------------