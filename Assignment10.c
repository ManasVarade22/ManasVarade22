#include <stdio.h>
#include <math.h>

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for(int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int choice;
    double a, b, result;
    int n;

    printf("\n--- Simple Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Factorial (x!)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            printf("Result = %.2lf\n", a + b);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            printf("Result = %.2lf\n", a - b);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            printf("Result = %.2lf\n", a * b);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &a, &b);
            if(b != 0)
                printf("Result = %.2lf\n", a / b);
            else
                printf("Error! Division by zero.\n");
            break;

        case 5:
            printf("Enter base and exponent: ");
            scanf("%lf %lf", &a, &b);
            result = pow(a, b);
            printf("Result = %.2lf\n", result);
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%d", &n);
            if(n < 0)
                printf("Factorial not defined for negative numbers.\n");
            else
                printf("Result = %lld\n", factorial(n));
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}