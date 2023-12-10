#include <iostream>
#include <string>

void unescape_string(std::string& s, bool unescape_backslash, char backslash_char, char double_quote_char, bool unescape_forward_slash) {
    size_t pos = 0;
    while ((pos = s.find('\\', pos)) != std::string::npos) {
        if (pos + 1 < s.length()) {
            if (s[pos + 1] == backslash_char && unescape_backslash) {
                s.replace(pos, 2, 1, backslash_char);
            } else if (s[pos + 1] == double_quote_char) {
                s.replace(pos, 2, 1, double_quote_char);
            } else if (s[pos + 1] == '/' && unescape_forward_slash) {
                s.replace(pos, 2, 1, '/');
            }
        }
        pos++;
    }
}

int main() {
    std::string s = "\"world\"";
    unescape_string(s, true, '\\', '\"', false);
    std::cout << s << std::endl;  // Output: "world"

    s = "\\\\world\\\\";
    unescape_string(s, true, '\\', '\"', false);
    std::cout << s << std::endl;  // Output: \world\

    s = "\\";
    unescape_string(s, true, '\\', '\"', false);
    std::cout << s << std::endl;  // Output: \
    
    return 0;
}
