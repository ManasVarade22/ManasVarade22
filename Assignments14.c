#include <stdio.h>
#include <math.h>

int main() {
    long long binary;
    int decimal = 0, i = 0, remainder;

    printf("Enter a binary number: ");
    scanf("%lld", &binary);

    while(binary != 0) {
        remainder = binary % 10;

        // Check if input is valid binary
        if(remainder != 0 && remainder != 1) {
            printf("Invalid binary number!\n");
            return 0;
        }

        decimal += remainder * pow(2, i);
        binary = binary / 10;
        i++;
    }

    printf("Decimal equivalent = %d\n", decimal);

    return 0;
}