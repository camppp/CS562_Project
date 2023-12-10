std::string subString(const std::string& hex_str, int length) {
    if (length > hex_str.length()) {
        throw std::invalid_argument("Length cannot be greater than the length of the input string");
    }
    return hex_str.substr(0, length);
}
