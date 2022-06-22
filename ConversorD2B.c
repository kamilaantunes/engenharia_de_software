#include<stdio.h>
#include<stdlib.h>

// Struct das pilhas
typedef struct {
	int topo; // indexador - guarda o indíce das posições do vetor
	int vetor[10];
} PilhaEstatica;

/*----------------------- Operações ------------------------------------*/

// Inicia a pilha
void iniciaPilhaEstatica(PilhaEstatica *p){
	p->topo = 0;
}

// Adiciona valor na pilha
void empihaPilhaEstatica(PilhaEstatica *pilha, int x){
	// Adiciona número x na posição indexada pelo topo
	pilha->vetor[pilha->topo] = x;

	// Incrementa o valor do topo
	pilha->topo++;
}

// Remove valor do topo da pilha
int desempilhaPilhaEstatica(PilhaEstatica *pilha){
	// Topo decrementado p retornar uma posição
	int aux = pilha->vetor[pilha->topo-1];
	pilha->topo--;

	return aux;
}

// Retorna o valor da pilha
int topoPilhaEstatica(PilhaEstatica *pilha){
	int ret = pilha->vetor[pilha->topo-1];

	return (ret);
}

// Imprime os valores na pilha
void imprimePilhaEstatica(PilhaEstatica *p, char nome[8]){
	printf("\nPilha %s = [", nome);
	
	for (int i = 0; i < p->topo; i++){
		printf("%d ", p->vetor[i]);
	}

	printf("]\n");
}

// Função para converssão de um número do arquivo para binários
int converteBinario(PilhaEstatica *pBin, int decimal){
	int decimSalva = decimal;
	int resultado[10];
	int i;
	int binario = 0;

	if (decimal == 1){
		empihaPilhaEstatica(pBin, 1);
	} else if (decimal == 0){
		empihaPilhaEstatica(pBin, 0);
	} else {
		for (i = 0; decimal > 0; i++){
			resultado[i] = decimal%2;
			decimal /= 2;
		}

		for (i = i - 1; i >= 0; i--){
			binario *= 10;
			binario += resultado[i];
		}

		empihaPilhaEstatica(pBin, binario);
	}
}

/*--------------------- Função main ------------------------*/
int main(int argc, const char * argv[]){
	printf("Numero de paramentros informados: %d\n", argc);

	if (argc != 3){
		printf("Quantidade de parametros invalida!");

		return 0;
	}

	FILE* entrada = fopen(argv[1], "r");
	FILE* saida = fopen(argv[2], "w");

	if (entrada == NULL || saida == NULL){
		printf("Erro: Algum dos arquivos nao pode ser criado corretamente!");

		return 0;
	}

	// Inicializando a pilha de entrada
	PilhaEstatica pilhaEntrada;
	iniciaPilhaEstatica(&pilhaEntrada);

	// Arquivo está vazio?
	char tst;

	if ((tst = fgetc(entrada)) == EOF){
		printf("Erro: arquivo invalido!\n");

		printf(saida, "Erro: arquivo invalido!");

		return 0;
	}

	// Retorna para o início do arquivo
	rewind(entrada);

	while ((tst = fgetc(entrada)) != EOF){
	if(!(tst =='0' || tst =='1' || tst =='2' || tst =='3' || tst =='4' || tst =='5' || tst =='6' || tst =='7' || tst =='8' || tst =='9' || tst =='\n')){
			printf("Erro: arquivo invalido!\n");

			fprintf(saida, "Erro: arquivo invalido!");

			return 0;
		}
	}

	rewind(entrada);

	int decimal;

	while (!feof(entrada)){
		fscanf(entrada, '%d', &decimal); // Obtem número inteiro do arquivo de entrada

		empihaPilhaEstatica(&pilhaEntrada, decimal); // Escrevendo no arquivo de saida
	}

	char imprimeNome1[8] = "Entrada";
	imprimePilhaEstatica(&pilhaEntrada, imprimeNome1);

	// Inicia pilha binário
	PilhaEstatica pilhaBinario;
	iniciaPilhaEstatica(&pilhaBinario);

	int temp = pilhaEntrada.topo;
	int i;

	for (i = 0; i < temp; i++){
		// Convertendo p binário
		converteBinario(&pilhaBinario, desempilhaPilhaEstatica(&pilhaEntrada));

		fprintf(saida, "%d\n", pilhaBinario.vetor[pilhaBinario.topo-1]); // Escrevendo número binário no arquivo de saída
	}

	char imprimeNome2[8] = "Saida";
	imprimePilhaEstatica(&pilhaBinario, imprimeNome2);

	// Fechando os arquivos
	fclose(entrada);
	fclose(saida);

	return 0;
}