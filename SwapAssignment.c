#include <stdio.h>
#include <stdlib.h>

int main() {
    int *a, *b, temp;

    a = (int *)malloc(sizeof(int));
    b = (int *)malloc(sizeof(int));

    if (a == NULL || b == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter two numbers:\n");
    scanf("%d %d", a, b);
    temp = *a;
    *a = *b;
    *b = temp;

    printf("After swapping:\n");
    printf("a = %d, b = %d\n", *a, *b);

    return 0;
}