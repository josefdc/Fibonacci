import matplotlib.pyplot as plt

# Datos proporcionados
n_values = [5, 10, 15, 20, 25, 30, 35, 40]
execution_times = [1506, 1271, 1232, 1084, 2293, 11646, 67620, 616310]

# Ajuste de curva
popt, pcov = curve_fit(func, n_values, execution_times)

# Crear datos ajustados
n_fit = np.linspace(5, 40, 100)
y_fit = func(n_fit, *popt)

plt.figure(figsize=(10, 6))
plt.plot(n_values, execution_times, 'bo', label="Datos reales")
plt.plot(n_fit, y_fit, 'r-', label=f'Aproximación: {popt[0]:.2f} * (2^({popt[1]:.2f}n))')
plt.title('Tiempo de ejecución de Fibonacci(2^n)')
plt.xlabel('Valor de n')
plt.ylabel('Tiempo de ejecución (microsegundos)')
plt.legend()
plt.grid(True)
plt.show()