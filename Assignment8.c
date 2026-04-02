#include <stdio.h>

int main() {
    float marks[5], total = 0, percentage;
    int i, pass = 1;

    // Input marks
    printf("Enter marks of 5 courses:\n");
    for(i = 0; i < 5; i++) {
        scanf("%f", &marks[i]);

        // Check pass condition (each subject >= 40)
        if(marks[i] < 40) {
            pass = 0;
        }

        total += marks[i];
    }

    // Check result
    if(pass == 0) {
        printf("\nResult: FAIL\n");
    } else {
        percentage = total / 5;
        printf("\nResult: PASS");
        printf("\nAggregate Percentage = %.2f%%\n", percentage);

        // Assign grade
        if(percentage >= 75)
            printf("Grade: Distinction\n");
        else if(percentage >= 60)
            printf("Grade: First Division\n");
        else if(percentage >= 50)
            printf("Grade: Second Division\n");
        else
            printf("Grade: Third Division\n");
    }

    return 0;
}