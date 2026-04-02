#include <stdio.h>
#include <math.h>

// Function to check prime
int isPrime(int n) {
    if(n <= 1)
        return 0;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
            return 0;
    }
    return 1;
}

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Function to find prime factors
void primeFactors(int n) {
    printf("Prime factors: ");
    for(int i = 2; i <= n; i++) {
        while(n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Square root
    if(num >= 0)
        printf("Square Root = %.2f\n", sqrt(num));
    else
        printf("Square Root not defined for negative numbers\n");

    // Square
    printf("Square = %d\n", num * num);

    // Cube
    printf("Cube = %d\n", num * num * num);

    // Prime check
    if(isPrime(num))
        printf("%d is a Prime number\n", num);
    else
        printf("%d is NOT a Prime number\n", num);

    // Factorial
    if(num >= 0)
        printf("Factorial = %lld\n", factorial(num));
    else
        printf("Factorial not defined for negative numbers\n");

    // Prime factors
    if(num > 1)
        primeFactors(num);
    else
        printf("No prime factors\n");

    return 0;
}