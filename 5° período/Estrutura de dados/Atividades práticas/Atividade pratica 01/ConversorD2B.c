#include <stdio.h>
#define tamanho 100

typedef struct pilha{
  int num[tamanho];
  int topo;
} PilhaEstatica;

void inicia(PilhaEstatica* pe){
	pe->topo = -1;
}

int vazia(PilhaEstatica* pe){
	if (pe->topo==-1){
        return 1;
    }

	return 0;
}

int isnum(char c){
	char nums[10] = {'0','1','2','3','4','5','6','7','8','9'};
	int is = 0;

	for (int i = 0; i < 10 && is == 0; i++){
        // Se for um número, retorna 1
		if (c == nums[i]) is = 1;
	}

	return is;
}

void pprint(PilhaEstatica* pe){
	for (int i = pe->topo; i > -1; i--){
		printf("%d",pe->num[i]);
	}

	printf("\n");
}

int pop(PilhaEstatica* pe){
	int val;

	val = pe->num[pe->topo];
	pe->topo--;

	return val;
}

int push(PilhaEstatica* pe, int dado){
	pe->topo++;
	pe->num[pe->topo] = dado;
}

void pinvert(PilhaEstatica* imp,PilhaEstatica* out){
	int val = 0;

	while (!vazia(imp)){
		val = val * 10;
		val = val + pop(imp);
	}

	push(out,val);
}

void pfprint(PilhaEstatica* pe, FILE* arq){
	while (!vazia(pe)){
		fprintf(arq, "%d\n",pop(pe));
	}
}

int main(int argc, const char * argv[]) {
    // Válida se o programa for execuável no estado atual
    if(argc!= 3) {
      printf("Quantidade de parametros invalidos!\n");

      return 0;
    }

    FILE* entrada = fopen(argv[1], "r");
    FILE* saida   = fopen(argv[2], "w");

    if (entrada == NULL) {
      printf("Erro ao criar o arquivo de entrada!\n");

      return 0;
    }

    if (saida == NULL) {
      printf("Erro ao criar o arquivo de saida!\n");

      return 0;
    }

	int num;
    int valid = 1;
    int ncl = 0; // ncl = número de caracteres por linha e um contador usado para voltar ao início da linha após a validação

	if (feof(entrada)){
		    valid = 0;
		}

	PilhaEstatica main,sub;
    inicia(&main);
    inicia(&sub);

    int tevealgo = 0;

	while (!feof(entrada)){
        int lido = 0;
        num = 0;

		for (char cha = fgetc(entrada); cha != '\n' && cha != EOF && valid; cha = fgetc(entrada)){
            lido = 1;
			valid = isnum(cha);
			num = (num * 10) + (cha-48);
		}

		if(!valid || !lido){
            // Se for inválido, sai do laço
            break;
        }

		tevealgo = 1;

		if (num == 0) {
			push(&main, 0);
		} else if (num == 1) {
			push(&main, 1);
		} else {
			while (num != 1){
				push(&main, num % 2);
				num = num / 2;
			}
			push(&main, num);
		}

		pinvert(&main,&sub);

		// Reiniciando as tabelas
		inicia(&main);
		printf("\n");
	}

	if(valid && tevealgo){
		pfprint(&sub, saida);

		return 1;
	}else{
		fprintf(saida ,"Arquivo invalido!");

		return -1;
	}
	return 0;
}