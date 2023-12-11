void rot(int* dest, const int* src, int size, int s) {
    // Initialize the destination array to all zeros
    reset(dest, size);

    // Copy the first s elements of the source array to the destination array
    cp(dest, src, s);

    // Copy the last n-s elements of the source array to the destination array
    cp(dest + s, src + s, size - s);

    // Copy the first s elements of the source array to the destination array
    cp(dest + size - s, src, s);
}
