++
#include <string>

bool IsDelimiter(char c) {
    return c == '\n';  // Assuming newline character as the line break boundary
}

std::string RetrieveNextSection(const char* mBuffer, int32_t& mBufferPosition) {
    int32_t start = mBufferPosition;
    while (mBuffer[mBufferPosition] != '\0') {
        if (IsDelimiter(mBuffer[mBufferPosition])) {
            break;
        }
        ++mBufferPosition;
    }
    int32_t end = mBufferPosition;
    if (mBuffer[mBufferPosition] == '\n') {
        ++mBufferPosition;  // Move past the line break boundary
    }
    return std::string(mBuffer + start, mBuffer + end);
}
