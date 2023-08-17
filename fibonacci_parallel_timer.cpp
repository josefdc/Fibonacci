#include <iostream>
#include <chrono>
#include <vector>
#include <omp.h>

std::vector<int> memoization;

int parallel_fibonacci(int n) {
    if (n <= 1)
        return n;

    if (memoization[n] != -1)
        return memoization[n];

    int fib1, fib2;
#pragma omp task shared(fib1) // Create tasks for parallel computation
    fib1 = parallel_fibonacci(n - 1);
#pragma omp task shared(fib2)
    fib2 = parallel_fibonacci(n - 2);
#pragma omp taskwait // Wait for the tasks to complete

    memoization[n] = fib1 + fib2; // Memoize the result

    return memoization[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    memoization.assign(n + 1, -1); // Initialize memoization array
    memoization[0] = 0;
    memoization[1] = 1;

    auto start = std::chrono::high_resolution_clock::now(); // Record the start time

#pragma omp parallel
#pragma omp single
    int fibNumber = parallel_fibonacci(n);

    auto end = std::chrono::high_resolution_clock::now(); // Record the end time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); // Calculate the execution time

    std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
