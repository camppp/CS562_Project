std::vector<UChar32> getCharacterFallback(UChar32 inputCharacter) {
    // Initialize the output vector
    std::vector<UChar32> fallbacks;

    // Check if the input character is in the table
    if (inputCharacter < 0x10000) {
        // Get the fallback characters for the input character
        fallbacks = fallbackTable[inputCharacter];
    }

    // Return the fallback characters
    return fallbacks;
}
