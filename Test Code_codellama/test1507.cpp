bool ValidateLicenseKey(const std::string& FromUser) {
    // Initialize a buffer to store the validated characters
    std::string validatedChars;

    // Iterate through the input string, checking each pair of characters for validity
    for (int i = 0; i < FromUser.length(); i += 2) {
        // Check if the current character is a valid hexadecimal digit
        if (!isxdigit(FromUser[i])) {
            // If the current character is not a valid hexadecimal digit, return false
            return false;
        }

        // If the current character is a valid hexadecimal digit, add it to the validated characters buffer
        validatedChars += FromUser[i];
    }

    // If all characters in the input string are valid hexadecimal digits, return true
    return true;
}
