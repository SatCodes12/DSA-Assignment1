#include <stdio.h>
#include <limits.h>

unsigned long long factorial_iterative(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        if (result > ULLONG_MAX / i) {
            printf("Overflow detected. Factorial too large to compute.\n");
            return 0; 
        }
        result *= i;
    }
    return result;
}


unsigned long long factorial_recursive(int n) {
    if (n == 0 || n == 1)
        return 1;
    unsigned long long temp_result = factorial_recursive(n - 1);
    if (temp_result > ULLONG_MAX / n) {
        printf("Overflow detected. Factorial too large to compute.\n");
        return 0; 
    }
    return n * temp_result;
}

int main() {
    int n;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number doesn't exist.\n");
        return 1;
    }

    
    unsigned long long result_iterative = factorial_iterative(n);
    if (result_iterative != 0)
        printf("Factorial of %d (iterative) = %llu\n", n, result_iterative);

    
    unsigned long long result_recursive = factorial_recursive(n);
    if (result_recursive != 0)
        printf("Factorial of %d (recursive) = %llu\n", n, result_recursive);

    return 0;
}