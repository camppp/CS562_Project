c
#include "noerr.h"

const char* GetError() {
    // Get the error code from the error handling module
    int errorCode = noerr_get_error_code();

    // Check if the error code is valid
    if (errorCode == NOERR_OK) {
        // No error, return an empty string
        return "";
    }

    // Get the error message from the error handling module
    const char* errorMessage = noerr_get_error_message(errorCode);

    // Return the error message
    return errorMessage;
}
