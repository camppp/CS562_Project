size_t count_len(const char* s) {
    size_t i = 0;
    while (s[i]) {
        ++i;
    }
    return i;
}
