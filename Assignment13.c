#include <stdio.h>

int main() {
    int num, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed digits: ");

    while(num != 0) {
        remainder = num % 10;   // get last digit
        printf("%d", remainder);
        num = num / 10;         // remove last digit
    }

    printf("\n");
    return 0;
}