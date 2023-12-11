void unescape_string(string& s, bool unescape_backslashes, char backslash_escape_char, bool unescape_double_quotes, char double_quote_escape_char, bool unescape_forward_slashes, char forward_slash_escape_char) {
    // Iterate through the string and unescape the appropriate characters
    for (int i = 0; i < s.length(); i++) {
        // Check if the current character is a backslash
        if (s[i] == '\\') {
            // Check if backslashes should be unescaped
            if (unescape_backslashes) {
                // Replace the backslash with the specified escape character
                s[i] = backslash_escape_char;
            }
        }
        // Check if the current character is a double quote
        else if (s[i] == '\"') {
            // Check if double quotes should be unescaped
            if (unescape_double_quotes) {
                // Replace the double quote with the specified escape character
                s[i] = double_quote_escape_char;
            }
        }
        // Check if the current character is a forward slash
        else if (s[i] == '/') {
            // Check if forward slashes should be unescaped
            if (unescape_forward_slashes) {
                // Replace the forward slash with the specified escape character
                s[i] = forward_slash_escape_char;
            }
        }
    }
}
