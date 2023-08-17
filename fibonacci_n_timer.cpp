#include <iostream>
#include <chrono>
#include <vector>  // Inclusión de la biblioteca necesaria para std::vector

long double fibonacci(int n) {
    if (n <= 1)
        return n;

    long double prev = 0;
    long double current = 1;

    for (int i = 2; i <= n; ++i) {
        long double next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

int main() {
    std::vector<int> values = {5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};

    for (int n : values) {
        // Start time
        auto start = std::chrono::high_resolution_clock::now();

        long double fibNumber = fibonacci(n);

        // End time
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
        std::cout << "Execution time for n = " << n << ": " << duration.count() << " microseconds" << std::endl;
        std::cout << "------------------------------------" << std::endl;
    }

    return 0;
}
