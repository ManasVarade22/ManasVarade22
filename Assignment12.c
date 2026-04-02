#include <stdio.h>

// Function to find GCD using Euclidean algorithm
int findGCD(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find smallest common divisor (other than 1)
int smallestCommonDivisor(int a, int b) {
    int min = (a < b) ? a : b;

    for(int i = 2; i <= min; i++) {
        if(a % i == 0 && b % i == 0)
            return i;
    }

    return -1; // no common divisor other than 1
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Smallest common divisor
    int scd = smallestCommonDivisor(num1, num2);
    if(scd == -1)
        printf("No common divisor other than 1.\n");
    else
        printf("Smallest Common Divisor = %d\n", scd);

    // GCD
    int gcd = findGCD(num1, num2);
    printf("GCD = %d\n", gcd);

    return 0;
}