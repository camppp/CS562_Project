#include <pcre.h>

int compile_regex(const char *pattern, int options) {
    pcre *re = pcre_compile(pattern, options, &error, &error_offset, NULL);
    if (re == NULL) {
        fprintf(stderr, "Error compiling regular expression: %s\n", error);
        return 1;
    }
    return 0;
}
