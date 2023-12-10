std::string convertWindows1252ToUTF8(const std::string& input) {
    std::string output;
    for (size_t i = 0; i < input.size(); i++) {
        const char* conv = table[input[i] - 0x80];
        int len = strlen(conv);
        if (len == 0) {
            continue;
        }
        output.append(conv, len);
    }
    return output;
}
