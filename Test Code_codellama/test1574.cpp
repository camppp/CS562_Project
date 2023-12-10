c
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
