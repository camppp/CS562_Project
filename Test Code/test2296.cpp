int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n')); // Skip leading spaces and newlines
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar() ) {
        i = (i<<3) + (i<<1) + (ch - '0'); // Multiply i by 10 and add the digit
    }
    ungetc(ch, stdin); // Put back the non-digit character for future input
    return i;
}
