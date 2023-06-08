# Definindo as variáveis
a = 2
b = 3
lista_string = "Flamengo"
resultao = a + b

# Estrutura de controle
if a == b:
    print('True')
else:
    print('False')

# Estrutura de repetição
for elemento in lista_string:
    print(elemento)

# Listas
lista1 = [1, 2, 3, 4, 5]
lista1[0] = "ovo"
print('substituicao de elemento', lista1),
lista2 = [1, "Mengo", lista1]

# For em listas
for elemento in lista2:
    print(elemento)

# Funções/ métodos
def soma(x, y):
    result = x + y
    return result

# Chamada em função
x = 5
y = 95
saida = (soma, y)
print(saida)