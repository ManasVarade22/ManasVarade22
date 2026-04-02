#include <stdio.h>

#define MAX 100

// Structure definition
struct Student {
    int roll;
    char name[50];
    float marks[3];
    float total;
    float percentage;
};

int main() {
    struct Student s[MAX];
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student details
    for(int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);

        printf("Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        printf("Enter marks of 3 subjects: ");
        for(int j = 0; j < 3; j++) {
            scanf("%f", &s[i].marks[j]);
        }

        // Calculate total and percentage
        s[i].total = 0;
        for(int j = 0; j < 3; j++) {
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 3;
    }

    // Display results
    printf("\n--- Student Results ---\n");
    for(int i = 0; i < n; i++) {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal Marks: %.2f", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);

        if(s[i].percentage >= 40)
            printf("\nResult: Pass\n");
        else
            printf("\nResult: Fail\n");
    }

    return 0;
}