#include <stdio.h>
#include <string.h>

int countOccurrences(const char *str, char target) {
    int count = 0;
    const char *p = str;

    while (p != NULL) {
        p = strchr(p, target);
        if (p != NULL) {
            count++;
            p++;
        }
    }

    return count;
}

int main() {
    const char *testString = "apple,banana,orange,grape";
    char targetChar = ',';
    int occurrences = countOccurrences(testString, targetChar);
    printf("The character '%c' occurs %d times in the string.\n", targetChar, occurrences);
    return 0;
}
