std::string FormatBinary(unsigned int n, unsigned int w) {
    std::string binary_string = std::bitset<w>(n).to_string();
    return binary_string;
}
