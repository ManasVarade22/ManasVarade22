#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure definition
struct Employee {
    char name[50];
    char designation[50];
    char gender;   // M or F
    char doj[15];  // Date of Joining
    float salary;
};

// Function to count total employees
int totalEmployees(int n) {
    return n;
}

// Function to count male and female employees
void countGender(struct Employee e[], int n) {
    int male = 0, female = 0;

    for(int i = 0; i < n; i++) {
        if(e[i].gender == 'M' || e[i].gender == 'm')
            male++;
        else if(e[i].gender == 'F' || e[i].gender == 'f')
            female++;
    }

    printf("\nMale Employees = %d", male);
    printf("\nFemale Employees = %d\n", female);
}

// Employees with salary > 10000
void highSalary(struct Employee e[], int n) {
    printf("\nEmployees with salary > 10000:\n");

    for(int i = 0; i < n; i++) {
        if(e[i].salary > 10000) {
            printf("%s\n", e[i].name);
        }
    }
}

// Employees with designation "Asst Manager"
void asstManager(struct Employee e[], int n) {
    printf("\nEmployees with designation 'Asst Manager':\n");

    for(int i = 0; i < n; i++) {
        if(strcmp(e[i].designation, "Asst Manager") == 0) {
            printf("%s\n", e[i].name);
        }
    }
}

int main() {
    struct Employee emp[MAX];
    int n;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    // Input details
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Designation: ");
        scanf("%s", emp[i].designation);

        printf("Gender (M/F): ");
        scanf(" %c", &emp[i].gender);

        printf("Date of Joining (dd/mm/yyyy): ");
        scanf("%s", emp[i].doj);

        printf("Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Function calls
    printf("\nTotal Employees = %d\n", totalEmployees(n));

    countGender(emp, n);

    highSalary(emp, n);

    asstManager(emp, n);

    return 0;
}