// Assuming HKEY_LOOKUP is a global array
char HKEY_LOOKUP[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

char rootToChar(int root) {
    return HKEY_LOOKUP[root & 0x00000007];
}
