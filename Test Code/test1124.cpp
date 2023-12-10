#include <cstring>

void concatenateToolVersion(char* buf, size_t buflen, const char* toolVersion) {
    size_t currentLength = strlen(buf);
    size_t remainingSpace = buflen - currentLength;

    if (remainingSpace > 0) {
        nvidia::strlcat(buf, buflen, toolVersion);
    }
}
