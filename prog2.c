#include <stdio.h>
#include <limits.h>

unsigned long long fibonacci_iterative(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long a = 0, b = 1, fib = 0;

    for (int i = 2; i <= n; i++) {
        if (ULLONG_MAX - b < a) {
            printf("Overflow detected. Fibonacci too large to compute.\n");
            return 0;
        }
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

unsigned long long fibonacci_recursive(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    unsigned long long temp1 = fibonacci_recursive(n - 1);
    unsigned long long temp2 = fibonacci_recursive(n - 2);

    if (ULLONG_MAX - temp1 < temp2) {
        printf("Overflow detected. Fibonacci too large to compute.\n");
        return 0;
    }
    
    return temp1 + temp2;
}

int main() {
    int n;

    printf("Enter a positive integer n to compute the nth Fibonacci number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fibonacci of a negative number doesn't exist.\n");
        return 1;
    }


    unsigned long long result_iterative = fibonacci_iterative(n);
    if (result_iterative != 0)
        printf("Fibonacci of %d (iterative) = %llu\n", n, result_iterative);


    unsigned long long result_recursive = fibonacci_recursive(n);
    if (result_recursive != 0)
        printf("Fibonacci of %d (recursive) = %llu\n", n, result_recursive);


    return 0;
}