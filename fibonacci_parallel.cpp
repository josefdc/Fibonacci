#include <iostream>
#include <vector>
#include <omp.h>

std::vector<long long> fibResults;

long long parallelFibonacci(int n) {
    if (n <= 1)
        return n;

    if (fibResults[n] != -1)
        return fibResults[n];

    long long fibNminus1, fibNminus2;

    #pragma omp task shared(fibNminus1)
    fibNminus1 = parallelFibonacci(n - 1);

    #pragma omp task shared(fibNminus2)
    fibNminus2 = parallelFibonacci(n - 2);

    #pragma omp taskwait

    fibResults[n] = fibNminus1 + fibNminus2;

    return fibResults[n];
}

long long fibonacci(int n) {
    fibResults.assign(n + 1, -1);
    fibResults[0] = 0;
    fibResults[1] = 1;

    #pragma omp parallel
    #pragma omp single
    return parallelFibonacci(n);
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    long long fibNumber = fibonacci(n);

    std::cout << "Fibonacci number at position " << n << ": " << fibNumber << std::endl;

    return 0;
}