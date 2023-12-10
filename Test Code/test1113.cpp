void rot(int* dest, const int* src, int size, int s) {
    int shift = s % size;  // Calculate the effective shift within the array size

    // Perform the rotation operation
    for (int i = 0; i < size; i++) {
        dest[(i + shift) % size] = src[i];
    }
}
