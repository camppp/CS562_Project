bool copyStringSecurely(const char* source, char* destination) {
    // Check if the source string is longer than the destination buffer
    if (strlen(source) > 100) {
        // Truncate the source string to fit in the destination buffer
        strncpy(destination, source, 100);
        // Return false to indicate that the string was truncated
        return false;
    } else {
        // Copy the source string to the destination buffer
        strcpy(destination, source);
        // Return true to indicate that the copy was successful without truncation
        return true;
    }
}