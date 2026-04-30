#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, count, lower, upper;

    printf("========================================\n");
    printf("     PSEUDO RANDOM NUMBER GENERATOR     \n");
    printf("========================================\n");

    printf("\nHow many random numbers do you want to generate? ");
    scanf("%d", &count);

    printf("\nChoose generation mode:\n");
    printf("1. Random numbers in a range [lower, upper]\n");
    printf("2. Random floating point numbers (0.0 to 1.0)\n");
    printf("3. Random numbers using custom seed\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {

        // --- Mode 1: Random integers in range ---
        case 1:
            printf("\nEnter lower bound: ");
            scanf("%d", &lower);
            printf("Enter upper bound: ");
            scanf("%d", &upper);

            if (lower >= upper) {
                printf("Error: Lower bound must be less than upper bound!\n");
                return 1;
            }

            // Seed with current time for true randomness each run
            srand((unsigned int)time(NULL));

            printf("\n--- %d Random Integers between %d and %d ---\n", count, lower, upper);
            for (int i = 1; i <= count; i++) {
                int num = (rand() % (upper - lower + 1)) + lower;
                printf("  Number %2d : %d\n", i, num);
            }
            break;

        // --- Mode 2: Random floats between 0 and 1 ---
        case 2:
            srand((unsigned int)time(NULL));

            printf("\n--- %d Random Floating Point Numbers (0.0 to 1.0) ---\n", count);
            for (int i = 1; i <= count; i++) {
                float num = (float)rand() / (float)RAND_MAX;
                printf("  Number %2d : %.6f\n", i, num);
            }
            break;

        // --- Mode 3: Custom seed (reproducible sequence) ---
        case 3: {
            unsigned int seed;
            printf("\nEnter seed value: ");
            scanf("%u", &seed);

            srand(seed);

            printf("\n--- %d Random Numbers with Seed %u ---\n", count, seed);
            for (int i = 1; i <= count; i++) {
                printf("  Number %2d : %d\n", i, rand());
            }

            // Show reproducibility
            printf("\n--- Regenerating with same seed %u (should match above) ---\n", seed);
            srand(seed);
            for (int i = 1; i <= count; i++) {
                printf("  Number %2d : %d\n", i, rand());
            }
            break;
        }

        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("\n========================================\n");
    printf("  Max possible value (RAND_MAX) = %d\n", RAND_MAX);
    printf("========================================\n");

    return 0;
}