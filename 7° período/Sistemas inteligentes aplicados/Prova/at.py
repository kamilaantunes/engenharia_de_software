import random

# Definição dos elementos do template
template_elements = [
    'layout', 'header', 'navbar', 'sidebar', 'content', 'footer',
    'títulos', 'textos', 'imagens', 'esquema de cores'
]

# Parâmetros do algoritmo genético
population_size = 50  # Tamanho da população
mutation_rate = 0.1  # Taxa de mutação
generations = 100  # Número de gerações

# Função de avaliação da solução (aqui é onde o usuário pode ajudar a avaliar)
def evaluate_solution(solution):
    # Aqui você pode implementar uma função para avaliar a qualidade da solução
    # Com base nos critérios de legibilidade, organização e estética definidos pela empresa
    # Quanto maior o valor retornado, melhor é a solução
    # Exemplo simplificado: pontuação é a quantidade de elementos do template presentes na solução
    score = sum(element in solution for element in template_elements)
    return score

# Função de criação de uma solução inicial
def create_solution():
    # Criação de uma solução aleatória
    solution = random.sample(template_elements, len(template_elements))
    return solution

# Função de cruzamento (crossover) entre duas soluções
def crossover(solution1, solution2):
    # Ponto de cruzamento aleatório
    crossover_point = random.randint(1, len(template_elements) - 1)
    
    # Filhos gerados pelo cruzamento
    child1 = solution1[:crossover_point] + solution2[crossover_point:]
    child2 = solution2[:crossover_point] + solution1[crossover_point:]
    
    return child1, child2

# Função de mutação em uma solução
def mutate(solution):
    # Mutação aleatória em um gene da solução
    mutated_solution = solution[:]
    index = random.randint(0, len(template_elements) - 1)
    mutated_solution[index] = random.choice(template_elements)
    
    return mutated_solution

# Algoritmo Genético
def genetic_algorithm():
    # Inicialização da população
    population = [create_solution() for _ in range(population_size)]
    
    for _ in range(generations):
        # Avaliação da população
        evaluated_population = [(solution, evaluate_solution(solution)) for solution in population]
        
        # Ordenar a população com base nas avaliações
        evaluated_population = sorted(evaluated_population, key=lambda x: x[1], reverse=True)
        
        # Seleção dos pais para reprodução (torneio)
        selected_parents = []
        for _ in range(population_size):
            tournament_size = 5
            tournament_contestants = random.sample(evaluated_population, tournament_size)
            winner = max(tournament_contestants, key=lambda x: x[1])
            selected_parents.append(winner[0])
        
        # Cruzamento e mutação para gerar a nova população
        new_population = []
        for i in range(0, population_size, 2):
            parent1 = selected_parents[i]
            parent2 = selected_parents[i + 1]
            
            child1, child2 = crossover(parent1, parent2)
            
            # Mutação
            if random.random() < mutation_rate:
                child1 = mutate(child1)
            if random.random() < mutation_rate:
                child2 = mutate(child2)
            
