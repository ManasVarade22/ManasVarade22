#include <stdio.h>
#include <math.h>

#define MAX 10

// Function for matrix addition
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int r, int c) {
    int sum[MAX][MAX];
    printf("\nResult of Addition:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

// Function to find saddle point
void saddlePoint(int a[MAX][MAX], int r, int c) {
    int found = 0;
    for(int i = 0; i < r; i++) {
        int min = a[i][0], col = 0;

        // Find minimum in row
        for(int j = 1; j < c; j++) {
            if(a[i][j] < min) {
                min = a[i][j];
                col = j;
            }
        }

        // Check if it is maximum in column
        int isSaddle = 1;
        for(int k = 0; k < r; k++) {
            if(a[k][col] > min) {
                isSaddle = 0;
                break;
            }
        }

        if(isSaddle) {
            printf("\nSaddle Point: %d\n", min);
            found = 1;
        }
    }

    if(!found)
        printf("\nNo Saddle Point found.\n");
}

// Function to find determinant of 2x2
float det2x2(float a[2][2]) {
    return a[0][0]*a[1][1] - a[0][1]*a[1][0];
}

// Function for inverse of 2x2 matrix
void inverse2x2(float a[2][2]) {
    float det = det2x2(a);

    if(det == 0) {
        printf("\nInverse not possible (determinant = 0)\n");
        return;
    }

    printf("\nInverse Matrix:\n");
    printf("%f %f\n", a[1][1]/det, -a[0][1]/det);
    printf("%f %f\n", -a[1][0]/det, a[0][0]/det);
}

// Function to check magic square
void magicSquare(int a[MAX][MAX], int n) {
    int sum = 0, diag1 = 0, diag2 = 0;

    // Sum of first row
    for(int j = 0; j < n; j++)
        sum += a[0][j];

    // Check rows
    for(int i = 0; i < n; i++) {
        int rowSum = 0;
        for(int j = 0; j < n; j++)
            rowSum += a[i][j];

        if(rowSum != sum) {
            printf("\nNot a Magic Square\n");
            return;
        }
    }

    // Check columns
    for(int j = 0; j < n; j++) {
        int colSum = 0;
        for(int i = 0; i < n; i++)
            colSum += a[i][j];

        if(colSum != sum) {
            printf("\nNot a Magic Square\n");
            return;
        }
    }

    // Diagonals
    for(int i = 0; i < n; i++) {
        diag1 += a[i][i];
        diag2 += a[i][n-i-1];
    }

    if(diag1 == sum && diag2 == sum)
        printf("\nIt is a Magic Square\n");
    else
        printf("\nNot a Magic Square\n");
}

int main() {
    int choice, r, c, a[MAX][MAX], b[MAX][MAX];

    printf("\nMatrix Operations Menu:\n");
    printf("1. Addition\n2. Saddle Point\n3. Inverse (2x2)\n4. Magic Square\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("\nEnter rows and columns: ");
            scanf("%d %d", &r, &c);

            printf("Enter Matrix A:\n");
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    scanf("%d", &a[i][j]);

            printf("Enter Matrix B:\n");
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    scanf("%d", &b[i][j]);

            addMatrices(a, b, r, c);
            break;

        case 2:
            printf("\nEnter rows and columns: ");
            scanf("%d %d", &r, &c);

            printf("Enter Matrix:\n");
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    scanf("%d", &a[i][j]);

            saddlePoint(a, r, c);
            break;

        case 3: {
            float mat[2][2];
            printf("\nEnter 2x2 matrix:\n");
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    scanf("%f", &mat[i][j]);

            inverse2x2(mat);
            break;
        }

        case 4:
            printf("\nEnter order of square matrix: ");
            scanf("%d", &r);

            printf("Enter Matrix:\n");
            for(int i=0;i<r;i++)
                for(int j=0;j<r;j++)
                    scanf("%d", &a[i][j]);

            magicSquare(a, r);
            break;

        default:
            printf("\nInvalid choice!\n");
    }

    return 0;
}