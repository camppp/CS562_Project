std::string DecimalToHex(int decimal) {
    std::string hex;
    while (decimal > 0) {
        hex = kHexConversion[decimal % 16] + hex;
        decimal /= 16;
    }
    return hex;
}
