size_t moveToStartOfCharSequence(size_t currentIndex, const char* str) {
    // Abort if already at the start of the string
    if (currentIndex == 0) return 0;

    // Move back one char to ensure we're in the middle of a char sequence
    const unsigned char* currentChar = (const unsigned char*)&str[currentIndex - 1];
    while ((*currentChar >= 0x80) && (*currentChar < 0xC0)) {
        currentChar--;
    }
    return currentChar - (const unsigned char*)str;
}
