import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Defining a function to fit to the data
def func(n, a, b):
    return a * np.log(n) + b

# Datos proporcionados
n_values = [5, 10, 50, 100, 500, 1000, 5000, 10000]
execution_times = [11, 18, 17, 37, 47, 49, 74, 116]

# Ajuste de curva
popt, pcov = curve_fit(func, n_values, execution_times)

# Crear datos ajustados
n_fit = np.linspace(5, 10000, 1000)
y_fit = func(n_fit, *popt)

plt.figure(figsize=(10, 6))
plt.plot(n_values, execution_times, 'bo', label="Datos reales")
plt.plot(n_fit, y_fit, 'r-', label=f'Aproximación: {popt[0]:.2f} * log(n) + {popt[1]:.2f}')
plt.title('Tiempo de ejecución de Fibonacci O(log n)')
plt.xlabel('Valor de n')
plt.ylabel('Tiempo de ejecución (microsegundos)')
plt.legend()
plt.grid(True)
plt.show()