import matplotlib.pyplot as plt

tamanho_matriz = ["2500x2500", "5000x5000", "10000x10000", "15000x15000"]
tamanho_arquivo = [6.1, 24.4, 36.6, 97.6] # Em MB

tempo = [1.94, 8.4, 33.89, 78.486]
memoria = [30.2, 119.6, 477.2, 1073.3]

mudanca1_time = [1.223, 5.6, 22.479, 52.089]
mudanca1_memory = [30.2, 119.6, 477.2, 1073.3]

mudanca2_time = [1.11, 4.412, 17.61, 39.842]
mudanca2_memory = [30.2, 119.6, 477.2, 1073.3]

def plot_linha(x, y, Y):
    plt.figure(figsize=(12, 8))
    plt.scatter(x, y, color='blue')
    plt.plot(x, y, color='red', label="Versão original")
    plt.scatter(x, Y, color='blue')
    plt.plot(x, Y, color='green', label="Versão alterada 1")
    plt.title('Memória usada em relação ao tamanho do arquivo')
    plt.xlabel('Tamanho do arquivo (MB)')
    plt.ylabel('Memória (MB)')
    plt.legend()
    plt.show()

plot_linha(tamanho_arquivo, mudanca1_time, mudanca2_time)