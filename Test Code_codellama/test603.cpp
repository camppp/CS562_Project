double getRandouble(const double min, const double max) {
    // Generate a random double value between 0 and 1
    double randomValue = (double)rand() / RAND_MAX;

    // Scale the random value to the desired range
    randomValue = min + (max - min) * randomValue;

    return randomValue;
}
