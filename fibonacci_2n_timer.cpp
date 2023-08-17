#include <iostream>
#include <chrono>

// Exponential time complexity Fibonacci function
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now();  // Record the start time

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    auto end = std::chrono::high_resolution_clock::now();    // Record the end time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate the execution time

    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl; 

    return 0;
}
