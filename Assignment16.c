#include <stdio.h>

#define MAX 100

int main() {
    int n, arr[MAX];
    int even[MAX], odd[MAX];
    int e = 0, o = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        // Partition into even and odd
        if(arr[i] % 2 == 0) {
            even[e++] = arr[i];
        } else {
            odd[o++] = arr[i];
        }
    }

    // Display even numbers
    printf("\nEven numbers:\n");
    for(int i = 0; i < e; i++) {
        printf("%d ", even[i]);
    }

    // Display odd numbers
    printf("\nOdd numbers:\n");
    for(int i = 0; i < o; i++) {
        printf("%d ", odd[i]);
    }

    printf("\n");
    return 0;
}