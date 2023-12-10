#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/random.h>
#include <errno.h>

int main() {
    int lower, upper, random_num;
    
    printf("Enter the lower bound of the range: ");
    scanf("%d", &lower);
    printf("Enter the upper bound of the range: ");
    scanf("%d", &upper);
    
    if (upper <= lower) {
        fprintf(stderr, "Error: Upper bound should be greater than the lower bound.\n");
        return 1;
    }
    
    if (getrandom(&random_num, sizeof(random_num), 0) != sizeof(random_num)) {
        perror("Error occurred while generating random number");
        return 1;
    }
    
    random_num = (random_num % (upper - lower + 1)) + lower;
    
    printf("Random number within the range [%d, %d]: %d\n", lower, upper, random_num);
    
    return 0;
}
