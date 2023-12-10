c
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char* my_ssprintf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    // Calculate the length of the resulting string
    int len = 0;
    for (const char* p = fmt; *p; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'd':
                case 'f':
                case 's':
                    len += 10;
                    break;
                default:
                    len++;
            }
        } else {
            len++;
        }
    }

    // Allocate memory for the resulting string
    char* str = (char*)malloc(len + 1);
    if (!str) {
        return NULL;
    }

    // Format the string
    va_list args_copy;
    va_copy(args_copy, args);
    vsprintf(str, fmt, args_copy);
    va_end(args_copy);

    return str;
}
