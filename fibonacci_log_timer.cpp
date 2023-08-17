#include <iostream>
#include <vector>
#include <chrono>
#include <limits>
#include <cmath>

typedef std::vector<std::vector<long double>> Matrix;

// Matrix multiplication
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

// Matrix Power
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

long double fibonacci(int n) {
    if (n <= 1)
        return n;

    Matrix base = {{1, 1}, {1, 0}};

    // We calculate the matrix raised to the power (n - 1).
    // This gives us a matrix with the necessary Fibonacci numbers.
    Matrix result = matrixPower(base, n - 1);

    // The Fibonacci number at position n is in the upper left corner of the matrix.
    return result[0][0];
}


int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now(); // Record the start time
    long double fibNumber = fibonacci(n);
    auto stop = std::chrono::high_resolution_clock::now(); // Record the end time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start); // Calculate the execution time

    std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
    std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
