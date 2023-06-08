# Problema:
    # Implementar um algoritmo subida da encosta para descobrir qual stringfoi definida pelo usuário

import random
import string

# Gerar solução
def gerar_solucao(tamanho = 5):
    return [random.choice(string.printable) for _ in range(tamanho)]  # Retorna caracteres aleatórios até o tamanho definido e gerar um vetor

# Expandir vizinhança
def expandir_vizinhanca(solucao):
    index = random.randint(0, len(solucao) - 1)
    solucao[index] = random.choice(string.printable)
    return solucao

    # Qualifica e quantifica quão boa a solução é
    # Comparativo entre as soluções geradas e a melhor

# Função objetivo
def funcao_objetivo(solucao):
    objetivo = list('UTFPR')    # O objetivo do algoritmo é conseguir gerar essa palavra novamente, através da solução aleatória
    valor_fit = 0   # Objetivo: minimizar a diferença entre as strings | Solução = Objetivo
    for i in range(len (objetivo)):
        s = solucao[i]      # Extraindo caracteres
        t = objetivo[i]     # Estraindo caracteres
        valor_fit += abs(ord(s) - ord(t))   # Função para avaliar se a função é boa | ord > 'tira' o valor referencial da letra da tabela ascii
    return valor_fit

# Fluxo
best = gerar_solucao()
best_score = funcao_objetivo(best)      # Avaliar se a solução best é boa
iteracao = 0

# print('Solucao ', best)
# print('Fit ', best scrore)

while True:
    iteracao += 1

    if best_score == 0:
        break

    nova_solucao = list(best)

    expandir_vizinhanca(nova_solucao)
    score_vizinho = funcao_objetivo(nova_solucao)

    if score_vizinho < best_score:
        best = nova_solucao
        best_score = score_vizinho
        print('Iteracao', iteracao, ' -- Solução:', "" .join(best), "-- Valor de avaliação:", best_score)