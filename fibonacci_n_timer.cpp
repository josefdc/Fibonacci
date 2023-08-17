#include <iostream>
#include <chrono>

int fibonacci(int n) {
    if (n <= 1)
        return n;

    int prev = 0;
    int current = 1;

    for (int i = 2; i <= n; ++i) {
        int next = prev + current;
        prev = current;
        current = next;
    }

    return current;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    // Start time
    auto start = std::chrono::high_resolution_clock::now();

    int fibNumber = fibonacci(n);

    // End time
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
