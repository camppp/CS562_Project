#include <stdio.h>

enum ErrorCode {
    INNO_GENERAL_ERROR = 0,
    INNO_INVALID_INPUT = 1,
    INNO_OUT_OF_MEMORY = 2,
    // ... other error codes
};

const char* getErrorDescription(enum ErrorCode code) {
    switch (code) {
        case INNO_GENERAL_ERROR:
            return "General error";
        case INNO_INVALID_INPUT:
            return "Invalid input";
        case INNO_OUT_OF_MEMORY:
            return "Out of memory";
        default:
            return "Unknown error";
    }
}

int main() {
    enum ErrorCode error = INNO_GENERAL_ERROR;
    printf("%s\n", getErrorDescription(error));
    return 0;
}
