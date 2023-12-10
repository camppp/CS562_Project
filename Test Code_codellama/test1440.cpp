std::string generateGASolution(int nPopX, int maxBitX, int maxBestX) {
    // Generate a random integer between 1 and maxBitX
    int length = rand() % (maxBitX - 1) + 1;

    // Generate a random binary string of the specified length
    std::string solution;
    for (int i = 0; i < length; i++) {
        solution += (rand() % 2) ? '1' : '0';
    }

    return solution;
}
