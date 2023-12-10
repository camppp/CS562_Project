#include <iostream>
#include <string>

int countComments(const std::string& shaderSource) {
    int commentCount = 0;

    // Iterate through the characters in the shader source code
    for (int i = 0; i < shaderSource.size(); i++) {
        // Check if the current character is a forward slash
        if (shaderSource[i] == '/') {
            // Check if the next character is a forward slash or a star
            if (i + 1 < shaderSource.size() && (shaderSource[i + 1] == '/' || shaderSource[i + 1] == '*')) {
                // Increment the comment count if the comment is not within a string literal or a character literal
                if (!isInStringLiteral(shaderSource, i) && !isInCharacterLiteral(shaderSource, i)) {
                    commentCount++;
                }
            }
        }
    }

    return commentCount;
}

// Check if the current character is within a string literal
bool isInStringLiteral(const std::string& shaderSource, int i) {
    // Check if the current character is a quote
    if (shaderSource[i] == '"') {
        // Check if the previous character is an escape character
        if (i > 0 && shaderSource[i - 1] == '\\') {
            // If the previous character is an escape character, the current character is not within a string literal
            return false;
        } else {
            // If the previous character is not an escape character, the current character is within a string literal
            return true;
        }
    }

    return false;
}

// Check if the current character is within a character literal
bool isInCharacterLiteral(const std::string& shaderSource, int i) {
    // Check if the current character is a single quote
    if (shaderSource[i] == '\'') {
        // Check if the previous character is an escape character
        if (i > 0 && shaderSource[i - 1] == '\\') {
            // If the previous character is an escape character, the current character is not within a character literal
            return false;
        } else {
            // If the previous character is not an escape character, the current character is within a character literal
            return true;
        }
    }

    return false;
}
