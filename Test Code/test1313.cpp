#include <iostream>
#include <string>

enum ErrorCode {
    E_MAX,
    E_MIN,
    E_INVALID
};

std::string handleError(ErrorCode code) {
    switch (code) {
        case E_MAX:
            return "Maximum limit reached";
        case E_MIN:
            return "Minimum limit reached";
        case E_INVALID:
            return "Invalid input";
        default:
            return "Unknown error";
    }
}

void someFunction() {
    // ... some code
    if (/* condition */) {
        abort();
        std::cout << handleError(E_MAX) << std::endl;
        return;
    }
    // ... some more code
}
