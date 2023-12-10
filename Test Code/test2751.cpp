#include <stdio.h>
#include <stdarg.h>

#define LOG_CRITICAL(format, ...) \
    do { \
        fprintf(stderr, "CRITICAL: "); \
        fprintf(stderr, format, __VA_ARGS__); \
        fprintf(stderr, "\n"); \
    } while (0)

int main() {
    const char* error_message = "Out of memory";
    LOG_CRITICAL("Critical error occurred: %s", error_message);
    return 0;
}
