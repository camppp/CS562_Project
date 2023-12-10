#include "misc.h"

bool starts_with(const char *x, const char *s)
{
    size_t nx = strlen(x), ns = strlen(s);

    if (nx < ns) {
        return false;  // If the string is shorter than the prefix, it cannot start with the prefix
    }

    for (size_t i = 0; i < ns; i++) {
        if (x[i] != s[i]) {
            return false;  // If any character differs, the string does not start with the prefix
        }
    }

    return true;  // All characters in the prefix match, so the string starts with the prefix
}
