#include <iostream>
#include <chrono>
#include <vector>

// Exponential time complexity Fibonacci function
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    std::vector<int> testValues = {5, 10, 15, 20, 25, 30, 35, 40};  // Recommended values for 2^n complexity

    for (int n : testValues) {
        auto start = std::chrono::high_resolution_clock::now();  // Record the start time

        std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

        auto end = std::chrono::high_resolution_clock::now();    // Record the end time
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout << "Execution time for n=" << n << ": " << duration.count() << " microseconds" << std::endl << std::endl;
    }

    return 0;
}
