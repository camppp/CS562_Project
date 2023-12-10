#include <stdio.h>

#define DEBUG_MSG(format, ...) printf("[%s:%d] " format "\n", __FILE__, __LINE__, ##__VA_ARGS__)

int main() {
    int errorCode = 404;
    DEBUG_MSG("Error code: %d", errorCode);

    char* functionName = "exampleFunction";
    DEBUG_MSG("Error occurred at function %s", functionName);

    return 0;
}
