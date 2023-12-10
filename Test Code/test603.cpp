#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

double getRandouble(const double min, const double max) {
    double temp = ((double)rand()) / (double)RAND_MAX;  // Generate a random value between 0 and 1
    temp = min + (max - min) * temp;  // Scale the random value to the specified range
    return temp;
}
