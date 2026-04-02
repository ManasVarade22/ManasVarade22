#include<stdio.h>

void main()
{
    float a,b;
    printf("Enter two numbers: \n");
    scanf("%f %f",&a,&b);

    int operation;
    printf("Choose operation: 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n");
    scanf("%d",&operation); 
    switch(operation)
    {
        case 1:
            printf("Result: %f\n", a + b);
            break;
        case 2:
            printf("Result: %f\n", a - b);
            break;
        case 3:
            printf("Result: %f\n", a * b);
            break;
        case 4:
            if(b != 0)
                printf("Result: %f\n", a / b);
            else
                printf("Error: Division by zero\n");
            break;
        default:
            printf("Operation is invalid.\n");
    }
    return;
}