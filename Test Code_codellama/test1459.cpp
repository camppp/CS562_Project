bool validateCharacterLiteral(const string& literal) {
    // Check if the literal starts and ends with a single quote
    if (literal.size() < 2 || literal[0] != '\'' || literal[literal.size() - 1] != '\'') {
        return false;
    }

    // Check if the literal contains any invalid characters
    for (int i = 1; i < literal.size() - 1; i++) {
        if (literal[i] == '\'') {
            // If the escape character is used, check if it is followed by a valid character
            if (i + 1 < literal.size() && literal[i + 1] != '\'' && literal[i + 1] != '\\') {
                return false;
            }
        } else if (literal[i] < 32 || literal[i] > 126) {
            // If the character is not printable, it is not a valid character literal
            return false;
        }
    }

    return true;
}
