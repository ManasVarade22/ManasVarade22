#include <stdio.h>

int main() {
    int num, original, remainder;
    int sum = 0;

    printf("Enter a 3-digit number: ");
    scanf("%d", &num);

    original = num;

    // Calculate sum of cubes of digits
    while(num != 0) {
        remainder = num % 10;
        sum = sum + (remainder * remainder * remainder);
        num = num / 10;
    }

    // Check Armstrong condition
    if(sum == original)
        printf("%d is an Armstrong number.\n", original);
    else
        printf("%d is NOT an Armstrong number.\n", original);

    return 0;
}