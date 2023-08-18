#include <iostream>
#include <chrono>
#include <vector>
#include <omp.h>
#include <gmpxx.h>

std::vector<mpz_class> memoization;

mpz_class parallel_fibonacci(int n) {
    if (n <= 1)
        return n;

    if (memoization[n] != -1)
        return memoization[n];

    mpz_class fib1, fib2;
#pragma omp task shared(fib1) // Create tasks for parallel computation
    fib1 = parallel_fibonacci(n - 1);
#pragma omp task shared(fib2)
    fib2 = parallel_fibonacci(n - 2);
#pragma omp taskwait // Wait for the tasks to complete

    memoization[n] = fib1 + fib2; // Memoize the result

    return memoization[n];
}

int main() {
    // Lista de valores intermedios para medir
    std::vector<int> values = {5, 10, 50, 100, 500, 1000, 5000, 10000, 15000, 20000};

    for (int n : values) {
        memoization.assign(n + 1, -1); // Initialize memoization array
        memoization[0] = 0;
        memoization[1] = 1;

        auto start = std::chrono::high_resolution_clock::now(); // Record the start time
#pragma omp parallel
#pragma omp single
        mpz_class fibNumber = parallel_fibonacci(n);
        auto end = std::chrono::high_resolution_clock::now(); // Record the end time
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate the execution time

        std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
        std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;
    }

    return 0;
}
