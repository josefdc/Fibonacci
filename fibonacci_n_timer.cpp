#include <iostream>
#include <chrono>

int fibonacci(int n) {
    // base case
    if (n <= 1)
        return n;

    int prev = 0;       // The (n-2)th Fibonacci number
    int current = 1;    // The (n-1)th Fibonacci number

    for (int i = 2; i <= n; ++i) {
        
        int next = prev + current;

        prev = current;   // Move the (n-1)th number to (n-2)th
        current = next;   // Move the next number to (n-1)th
    }

    return current;      // Return the calculated Fibonacci number
}


int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    auto start = std::chrono::high_resolution_clock::now(); // Record the start time

    int fibNumber = fibonacci(n);

    auto end = std::chrono::high_resolution_clock::now(); // Record the end time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate the execution time

    std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
