#include <cstdlib>

int rand_int(int min, int max)
{
    // Generate a random integer in the range [0, RAND_MAX]
    int random_value = rand() % (RAND_MAX + 1);

    // Scale and shift the result to fit within the desired range
    int random_int = random_value * (max - min + 1) / (RAND_MAX + 1) + min;

    return random_int;
}
