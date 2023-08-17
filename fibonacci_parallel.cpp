#include <iostream>
#include <vector>
#include <chrono>  // Inclusión de la librería para medir tiempo

// Definición del tipo de matriz que contendrá números de tipo long double.
typedef std::vector<std::vector<long double>> Matrix;

/**
 * @brief Multiplica dos matrices y devuelve el resultado.
 *
 * @param a Primera matriz.
 * @param b Segunda matriz.
 * @return Resultado de la multiplicación de matrices.
 */
Matrix matrixMultiply(const Matrix &a, const Matrix &b) {
    int n = a.size();
    int m = b[0].size();
    int p = b.size();
    Matrix result(n, std::vector<long double>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

/**
 * @brief Eleva una matriz a una potencia usando exponenciación rápida.
 *
 * @param mat Matriz a elevar.
 * @param exp Exponente.
 * @return Matriz elevada a la potencia exp.
 */
Matrix matrixPower(const Matrix &mat, int exp) {
    if (exp == 1) {
        return mat;
    }
    if (exp % 2 == 0) {
        Matrix halfPower = matrixPower(mat, exp / 2);
        return matrixMultiply(halfPower, halfPower);
    } else {
        Matrix halfPower = matrixPower(mat, (exp - 1) / 2);
        return matrixMultiply(matrixMultiply(halfPower, halfPower), mat);
    }
}

/**
 * @brief Calcula el n-ésimo número de Fibonacci usando exponenciación de matrices.
 *
 * @param n Posición del número de Fibonacci a calcular.
 * @return Número de Fibonacci en la posición n.
 */
long double fibonacci(int n) {
    if (n <= 1)
        return n;

    Matrix base = {{1, 1}, {1, 0}};
    Matrix result = matrixPower(base, n - 1);

    return result[0][0];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Inicio de la medición del tiempo
    auto start = std::chrono::high_resolution_clock::now();

    long double fibNumber = fibonacci(n);

    // Fin de la medición del tiempo
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
