import matplotlib.pyplot as plt

tamanho_matriz = ["2500x2500", "5000x5000", "10000x10000", "15000x15000"]
tamanho_arquivo = [6.1, 24.4, 36.6, 97.6] # Em MB

mudanca1_time = [1.223, 5.6, 22.479, 52.089]
mudanca2_time = [1.11, 4.412, 17.61, 39.842]
mudanca3_time = [0.9, 3.459, 13.63, 31.06] # Leitura diferente
mudanca4_time = [0.24, 0.97, 3.98, 8.77]

tempo = [1.94, 8.4, 33.89, 78.486]
memoria = [30.2, 119.6, 477.2, 1073.3]
mudanca5_time = [0.058, 0.232, 0.907, 2.054]
memoria5 = [33.2, 127, 515.2, 1176.3]

def plot_linha(x, y, y2, z, z2):
    fig, axs = plt.subplots(1, 2, figsize=(20, 14))

    axs[0].scatter(x, y, color='blue')
    axs[0].plot(x, y, color='red', label="Versão original")
    axs[0].scatter(x, y2, color='blue')
    axs[0].plot(x, y2, color='green', label="Última versão")
    axs[0].set_title('Tempo de execução em relação ao tamanho do arquivo')
    axs[0].set_xlabel('Tamanho do arquivo (MB)')
    axs[0].set_ylabel('Tempo (s)')
    axs[0].legend()

    axs[1].scatter(x, z, color='blue')
    axs[1].plot(x, z, color='red', label="Versão original")
    axs[1].scatter(x, z2, color='blue')
    axs[1].plot(x, z2, color='green', label="Última versão")
    axs[1].set_title('Uso de memória em relação ao tamanho do arquivo')
    axs[1].set_xlabel('Tamanho do arquivo (MB)')
    axs[1].set_ylabel('Memória (MB)')
    axs[1].legend()

    plt.show()

plot_linha(tamanho_arquivo, tempo, mudanca5_time, memoria, memoria5)