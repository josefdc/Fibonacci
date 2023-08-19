#include <iostream>
#include <vector>
#include <chrono>
#include <limits>
#include <cmath>

typedef std::vector<std::vector<long double>> Matrix;

/**
 * Multiplica dos matrices y devuelve el resultado.
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
 * Eleva una matriz a una potencia usando exponenciación rápida.
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
 * Calcula el n-ésimo número de Fibonacci usando exponenciación de matrices.
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

int maxDigitsLongDouble() {
    // Usamos la base 10 para calcular el número máximo de dígitos que puede representar un long double
    return -std::log10(std::numeric_limits<long double>::epsilon());
}

int main() {
    // Lista de valores recomendados para medir
    std::vector<int> values = {5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000};

    for (int n : values) {
        auto start = std::chrono::high_resolution_clock::now();
        long double fibNumber = fibonacci(n);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

        std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
        std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;
    }

  //  std::cout << "Maximum number of digits a long double can represent accurately: " << maxDigitsLongDouble() << std::endl;

    return 0;
}
