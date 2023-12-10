c
char* modifyHTTPDate(const char* httpdate) {
    char* buf = (char*)malloc(strlen(httpdate) + 1);
    const char* ptr1 = httpdate;
    char* ptr2 = buf;

    do {
        if (*ptr1 == ' ') {
            *ptr2++ = ';';
        } else {
            *ptr2++ = *ptr1;
        }
    } while (*ptr1++ != '\0');

    *ptr2 = '\0';
    return buf;
}
