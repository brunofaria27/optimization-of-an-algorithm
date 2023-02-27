# Fazer testes com tamanho: 100000 - 1000000 - 10000000 - 100000000
# 5000x1000 - 10000x2000 - 15000x4000 - 20000x8000
import matplotlib.pyplot as plt

tamanho_matriz = ["5000x1000", "10000x2000", "15000x4000", "20000x8000"]
tamanho_arquivo = ["17.4 MB", "69.7 MB", "209.2 MB", "557.8 MB"]
tempo = [10, 20, 30, 40]

# Gráfico de barras
def plot_tempo():
    plt.bar(tamanho_matriz, tempo)
    plt.title('Tempo de execução para diferentes tamanhos de arquivo')
    plt.xlabel('Tamanho do arquivo')
    plt.ylabel('Tempo (s)')
    plt.show()

# Gráfico de dispersão
def plot_dispersion():
    plt.scatter(tamanho_arquivo, tempo)
    plt.title('Tempo de execução em relação ao tamanho do arquivo')
    plt.xlabel('Tamanho do arquivo')
    plt.ylabel('Tempo (s)')
    plt.show()

# Gráfico de linha
def plot_linha():
    plt.plot(tamanho_matriz, tempo)
    plt.title('Tempo de execução em relação ao tamanho da matriz')
    plt.xlabel('Tamanho da matriz')
    plt.ylabel('Tempo (s)')
    plt.show()

# Gráfico de pizza
def plot_pizza():
    plt.pie(tempo, labels=tamanho_matriz)
    plt.title('Tempo de execução para diferentes tamanhos de arquivo')
    plt.show()

# Chama cada função para gerar um gráfico para cada tamanho do arquivo
for i in range(len(tamanho_matriz)):
    plot_tempo()
    plot_dispersion()
    plot_linha()
    plot_pizza()