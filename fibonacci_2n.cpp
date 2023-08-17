#include <iostream>

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

    std::cout << "Fibonacci(" << n << ") = " << fibonacci(n) << std::endl;

    return 0;
}