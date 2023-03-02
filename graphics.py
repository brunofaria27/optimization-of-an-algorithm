import matplotlib.pyplot as plt

tamanho_matriz = ["5000x1000", "10000x2000", "15000x4000", "20000x8000"]
tamanho_arquivo = [17.4, 69.7, 209.2, 557.8] # Em MB
tempo = [1.551, 6.952, 21.420, 66.780]
memoria = [24.2, 95.7, 286.5, 763.3]

# Gráfico de linha para o tamanho da matriz e tempo de execução
def plot_linha(x, y):
    plt.figure(figsize=(8, 6))
    plt.scatter(x, y, color='blue')
    plt.plot(x, y, color='red')
    plt.title('Memória usada em relação ao tamanho do arquivo')
    plt.xlabel('Tamanho do arquivo (MB)')
    plt.ylabel('Memória (MB)')
    plt.show()

plot_linha(tamanho_arquivo, tempo)