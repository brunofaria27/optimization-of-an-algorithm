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

import numpy as np
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression

# Gerando dados aleatórios
X = np.array([]).reshape((-1, 1))
y = np.array([])

# Criando objeto de regressão linear
model = LinearRegression()

# Treinando o modelo com os dados
model.fit(X, y)

# Fazendo previsões com o modelo treinado
y_pred = model.predict(X)

# Plotando o gráfico com os dados e a linha de regressão
plt.scatter(X, y)
plt.plot(X, y_pred, color='red', label="Regressão linear")
plt.xlabel('Tamanho do arquivo (MB)')
plt.ylabel('Tempo (s)')
plt.legend()
plt.show()
