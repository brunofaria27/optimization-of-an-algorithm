import matplotlib.pyplot as plt

tamanho_matriz = ["2500x2500", "5000x5000", "10000x10000", "15000x15000"]
tamanho_arquivo = [6.1, 24.4, 36.6, 97.6] # Em MB
tempo = [1.94, 8.4, 33.89, 78.486]
memoria = [30.2, 119.6, 477.2, 1073.3]

def plot_linha(x, y):
    plt.figure(figsize=(8, 6))
    plt.scatter(x, y, color='blue')
    plt.plot(x, y, color='red')
    plt.title('Memória usada em relação ao tamanho do arquivo')
    plt.xlabel('Tamanho do arquivo (MB)')
    plt.ylabel('Memória (MB)')
    plt.show()

plot_linha(tamanho_arquivo, memoria)