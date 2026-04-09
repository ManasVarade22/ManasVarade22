#include <stdio.h>
#include <math.h>

int main() {
    int n;
    double x, sum = 0.0, term;
    int sign = 1;

    // Input
    printf("Enter the value of x (in degrees): ");
    scanf("%lf", &x);

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    // Convert degrees to radians
    double x_rad = x * (3.14159265358979 / 180.0);

    // Calculate sine series
    term = x_rad;  // First term is x itself

    for (int i = 0; i < n; i++) {
        sum += sign * term;
        sign *= -1;  // Alternate sign

        // Next term: multiply by x^2 / ((2i+2)*(2i+3))
        term *= (x_rad * x_rad) / ((2 * i + 2) * (2 * i + 3));
    }

    printf("\n--- Sine Series Result ---\n");
    printf("sin(%.2f degrees) using %d terms = %.6f\n", x, n, sum);
    printf("Actual sin value (math.h)          = %.6f\n", sin(x_rad));
    printf("Difference                         = %.6f\n", fabs(sin(x_rad) - sum));

    return 0;
}