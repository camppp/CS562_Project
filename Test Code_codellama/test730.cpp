#include <stdio.h>
#include <stdlib.h>
#include <sys/random.h>

int main() {
    int lower_bound, upper_bound, random_integer;

    // Prompt the user to input the lower and upper bounds of the range
    printf("Enter the lower bound: ");
    scanf("%d", &lower_bound);
    printf("Enter the upper bound: ");
    scanf("%d", &upper_bound);

    // Check if the upper bound is less than or equal to the lower bound
    if (upper_bound <= lower_bound) {
        printf("Error: The upper bound must be greater than the lower bound.\n");
        return 1;
    }

    // Generate a random integer within the specified range using the getrandom system call
    random_integer = getrandom(sizeof(int), lower_bound, upper_bound);

    // Display the generated random integer
    printf("The generated random integer is: %d\n", random_integer);

    return 0;
}
