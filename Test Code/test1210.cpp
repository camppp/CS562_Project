#include <cstdlib>

int rand_int(int min, int max)
{
    // Ensure min <= max
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }

    // Generate a random integer within the specified range
    int range = max - min + 1;
    int random_number = min + rand() % range;

    return random_number;
}
