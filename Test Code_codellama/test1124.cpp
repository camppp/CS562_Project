c
#include <string.h>

void concatenateToolVersion(char* buf, size_t buflen, const char* toolVersion) {
    // Check if the buffer is large enough to hold the tool version string
    if (buflen < strlen(toolVersion)) {
        // If the buffer is too small, truncate the tool version string to fit
        toolVersion = strndup(toolVersion, buflen - 1);
    }

    // Concatenate the tool version string to the buffer using strlcat
    nvidia::strlcat(buf, toolVersion, buflen);
}
