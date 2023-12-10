c
size_t moveToStartOfCharSequence(size_t currentIndex, const char* str) {
    // Abort if already at the start of the string
    if (currentIndex == 0) return false;

    // Move back one char to ensure we're in the middle of a char sequence
    do {
        currentIndex--;
    } while ((str[currentIndex] >= 0x80) && (str[currentIndex] < 0xC0));

    return currentIndex;
}
