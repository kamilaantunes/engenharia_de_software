#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include<locale.h>

// #define TamNome 100

typedef struct InfPacientes{
    int codPac;
    char nomePac[100];
    char sexoPac;
    int idadePac;
    char pesoPac;
    float alturaPac;
    char telefonePac;
}Informacoes;

/******************************************************************************************************************************************************************************/

// Lista Ordenada
typedef struct NoLista* PtrNoLista;

typedef struct NoLista{
    Informacoes dados;
    PtrNoLista proximo;
    PtrNoLista anterior;
}NoLista;

/******************************************************************************************************************************************************************************/
// Implementação da lista ordenada

typedef struct {
    PtrNoLista inicio;
    PtrNoLista fim;
}ListaClinica;


// Inicializando a lista ordenada
void iniciaListaClinica(ListaClinica *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

// Verificando se a lista está vazia
bool verificaListaVazia(ListaClinica *lista){
    return (lista->inicio == NULL);
}

// Separando os conteúdos coletadas do arquivo de entrada
void separaConteudo(PtrNoLista paciente, char conteudo[100]){
    int i, k = 0;
    int num = 0;
    char aux[10] = {};
    char nome[100] = {};
    char sexo;
    int idade = 0;
    char auxIdade[5] = {};
    char peso[8] = {};
    char alturac[10] = {};
    double alturad;
    char telefone[15] = {};

    int dadoNum = 1;

    for (i = 0; i < strlen(conteudo); i++){
        // Numerando de acordo com o indice da linha
        if (dadoNum == 1){
            // Pesquisando o cod do paciente, transformando de string p inteiro
            if (conteudo[i] >= 48 && conteudo[i] <= 57){
                aux[k] = conteudo[i];

                if (num != 0){
                    num += (aux[k] - '0');
                } else {
                    num = (aux[k] - '0');
                }

                num *= 10;
                k++;
            } else if (conteudo[i] ==','){
                num /= 10;
                paciente->dados.codPac = num;
                dadoNum++;
            }
        }

        // Pesquisando o nome do paciene na linha e atribuindo à struct
        else if (dadoNum == 2){
            if (!(conteudo[i] == ',')){
                nome[strlen(nome)] = conteudo[i];
            } else {
                strcpy(paciente->dados.nomePac, nome);
                
                dadoNum++;
            }
        }

        // Pesquiso o sexo do paciente na linha e atribuindo à struct
        else if (dadoNum == 3){
            if (!(conteudo[i] == ',')){
                sexo = conteudo[i];
            } else {
                paciente->dados.sexoPac = sexo;

                dadoNum++;
            }
        }

        // Buscando a idade do paciente na linha, transformando de string p inteiro
        else if (dadoNum == 4){
            if (conteudo[i] >= 48 && conteudo[i] <= 57){
                auxIdade[k] = conteudo[i];

                if (idade != 0){
                    idade += (auxIdade[k] - '0');
                } else {
                    idade = (auxIdade[k] - '0');
                }

                idade *= 10;
                k++;
            } else if (conteudo[i] == ','){
                idade /= 10;
                paciente->dados.idadePac = idade;

                dadoNum++;
            }
        }

        // Pesquisando o peso do paciente e atribuindo à struct
        else if (dadoNum == 5){
            if(!(conteudo[i] == ',')){
                peso[strlen(peso)] = conteudo[i];
            } else {
                strcpy(paciente->dados.pesoPac, peso);

                dadoNum++;
            }
        }

        // Pesquisando a altura do paciente e transformando de string para float e atribuindo à struct
        else if (dadoNum == 6){
            if (!(conteudo[i] == ',')){
                alturac[strlen(alturac)] = conteudo[i];
            } else {
                char *nptr = &alturac;
                alturad = atof(nptr);

                paciente->dados.alturaPac = alturad;
                
                dadoNum++;
            }
        }

        // Pesquisando o telefone do paciente e atribuindo à struct
        else if (dadoNum == 7){
            if (!(conteudo[i] == '}')){
                telefone[strlen(telefone)] = conteudo[i];
            } else {
                strcpy(paciente->dados.telefonePac, telefone);

                dadoNum++;
            }
        }
    }
}

// Inserido elementos/nós na lista
void insereElementosLista(ListaClinica *lista, char conteudo[100]){

    PtrNoLista novo = malloc(sizeof(NoLista));

    // Inserindo elemnetos caso a lista esteja vazia
    if (verificaListaVazia(lista)){
        lista->inicio = novo; // Início da lista recebe o novo
        lista->fim = novo; // Fim da lista também recebe novo o pq a lista estava vazia
        novo->proximo = novo; // Próximo do novo aponta p ele mesmo
        novo->anterior = novo; // Anterior do novo apontap ele mesmo tb

        // Inserção caso o elemento a ser inserido seja menor comparado ao inicial
    } else if (novo->dados.codPac < lista->inicio->dados.codPac){
        novo->proximo = lista->inicio; // Novo se torna o início da lista
        novo->anterior = lista->fim; // Anterior do novo aponta o fim da lista
        novo->proximo->anterior = novo; // Anterior do início aponta p novo
        lista->inicio = novo; // Início da lista recebe o novo elemnte
        lista->fim->proximo = novo; // Próximo do fima da lista aponta p novo

        // Inserção caso o elemento a ser inserido seja maior que o final
    } else if (novo->dados.codPac > lista->fim->dados.codPac){
        novo->anterior = lista->fim; // Anterior do novo aponta p o fim da lista
        novo->proximo = lista->inicio; // Próximo do novo aponta p o início da lista
        lista->fim->proximo = novo; // Próximo do fim da lista aponta p o novo
        lista->fim = novo; // Fim da lista recebe o novo

        // Inserindo caso o elemnte seja inserido no meio da lista
    } else {
        PtrNoLista aux = lista->inicio;

        // Verifica se o valor inserido é maior que o código 
        while (aux->proximo != NULL && novo->dados.codPac > aux->proximo->dados.codPac){
            // Caso seja maior, guardará o próximo da fila
            aux = aux->proximo;
        }

        // Quando não for maior, insere o novo na posição guardada
        novo->proximo= aux->proximo;

        // Anterior do novo recebe aux
        novo->anterior = aux;

        // Anterior do próximo do novo recebe novo
        novo->proximo->anterior = novo;

        // Próximo do auxiliar recebe o novo
        aux->proximo = novo;
    }
}

// Imprimindo os dados em ordem crescente
void imprimeCrescente(ListaClinica lista, FILE* saida){
    // Se a lista não estiver vazia, imprime as informações do início ao fim da lista
    if (!verificaListaVazia(&lista)){
        PtrNoLista aux = lista.inicio;

        do {
            // Imprime na saída e no compilador em ordem crescente
            printf("{%d, %s, %c, %d, %s, %.2f, %s}\n", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac, aux->dados.telefonePac);
            fprintf(saida,"{%d, %s, %c, %d, %s, %.2f, %s}\n", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac, aux->dados.telefonePac);

            aux = aux->proximo;
        } while (aux != lista.inicio);
    }
}

// Imprimindo os dados em ordem descrescente
void imprimeDecrescente(ListaClinica lista, FILE* saida){
    // Se a lista não estivver vazia. imprime as informações do fim para o início
    if (!verificaListaVazia(&lista)){
        PtrNoLista aux = lista.fim;

        do  {
            // Imprime na saída e no compilador em ordem decrescente
            printf("{%d, %s, %c, %d, %s, %.2f, %s}\n", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac, aux->dados.telefonePac);
            fprintf(saida,"{%d, %s, %c, %d, %s, %.2f, %s}\n", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac, aux->dados.telefonePac);

            aux = aux->anterior;
        } while (aux != lista.inicio);

        // Imprime o primeiro elemente da lista na saída e no compilador
                printf("{%d, %s, %c, %d, %s, %.2f, %s}", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac, aux->dados.telefonePac);
                fprintf(saida,"{%d, %s, %c, %d, %s, %.2f, %s}", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac, aux->dados.telefonePac);
    }
}

/*-------------------------------- Função principal ------------------------------------------------*/

int main(int argc, const char * argv[]){
    setlocale(LC_ALL, "Portuguese"); // Definição para uso de caracteres especiais

    if (argc != 3){
        printf("Quantidade de parâmetros inválidas!\n");

        return 1;
    }

    FILE* entrada = fopen(argv[1], "r");
    FILE* saida = fopen(argv[2], "w");
    
    ListaClinica lista;
    iniciaListaClinica(&lista);

    char linha[50];
    char* armazenaDados[100];

    int i = 0, j = 0, linhaNum = 0, possuiDados = 0;
    int numReceb, numBus, numVirg;
    PtrNoLista aux = lista.inicio;

    while (fgets(linha, 100, entrada) != !EOF){
        // Zerando a variável de cada linha lida
        numVirg = 0;

        for (j = 0; j < strlen(linha); j++){
            if (linha[j] == 4){
                numVirg++;
            } else if (linha[j] != '{' && linha[j] != '}'){
                possuiDados++;
            }
        }

        // Passando pelas informações no arquivo de entrada
        if (!(linha[0] >= 48 && linha[0] <= 57)){
            if (numVirg != 6){
                printf("Arquivo inválido!\n");
                fprintf(saida, "Arquivo inválido!\n");

                return 1;
            }

            // Controle p erros de qntd de caracteres
            if (possuiDados == 0){
                printf("Arquivo inválido!\n");
                fprintf(saida, "Arquivo inválido!\n");

                return 1;
            }

            // Insere o cod e as informações na lista
            insereElementosLista(&lista, linha);

            // Guarda a operação a ser realizada e o número pesquisado, se for o caso
        } else if (linha[0] >= 48 && linha[0] <= 57){
            linhaNum++;

            int cod = 0, ind = 0;

            // Converte o número de string p inteiro
            while (linha[ind] >= 48 && linha[ind] <= 57){
                if (cod == 0){
                    cod = (linha[ind] - '0');
                } else {
                    cod += (linha[ind] - '0');
                }

                cod *= 10;
                ind++;
            }

            cod /= 10;

            // Verifica se as operações 1, 2 ou 3
            // Caso 3: guarda os dois valores do final do arquivo de entrada - a operação e o valor a ser pesquisado
            if (linhaNum == 1){
                numReceb = cod;
            } else if (linhaNum == 2){
                numBus = cod;
            } else {
                printf("Elemento não encontrado!\n");
                fprintf(saida, "Elemento não encontrado!\n");
            }
        }
    }

    // Verifica se o elemento a ser buscado existe ou não
    int count = 0;

    switch (numReceb){
        // Caso 1: imprime a lista em ordem crescente
        case 1:
            imprimeCrescente(lista, saida);
            break;

        // Caso 2: imprime em ordem decrescente
        case 2:
            imprimeDecrescente(lista, saida);
            break;

        // Caso 3: pesquisa o número abaixo dele na lista e retorno no arquivo
        case 3:
            aux = lista.inicio; // Armazena elemento inicial da lista em aux

            // Se o elemento estiver count é incrementado e éretornado
            do {
                if (aux->dados.codPac == numBus){
                    printf("{%d, %s, %c, %d, %s, %.2f, %s}\n", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac,aux->dados.telefonePac);
                    fprintf(saida,"{%d, %s, %c, %d, %s, %.2f, %s}\n", aux->dados.codPac, aux->dados.nomePac, aux->dados.sexoPac, aux->dados.idadePac, aux->dados.pesoPac, aux->dados.alturaPac, aux->dados.telefonePac);

                    count++;
                }
                aux = aux->proximo;
            } while (aux != lista.fim->proximo);

            // Caso count não seja incrementado - o elemento pesquisado não existe na lista
            if (count == 0){
                printf("Elemento não encontrado!\n");
                fprintf(saida, "Elemento não encontrado!\n");
            }
            break;

            default:
                printf("Arquivo inválido!\n");
                fprintf(saida, "Arquivo inválido!\n");

                break;
    }

    fclose(entrada);
    fclose(saida);

    return 0;
}