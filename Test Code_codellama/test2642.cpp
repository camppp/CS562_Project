c++
std::string RetrieveNextSection(const char* mBuffer, int32_t& mBufferPosition) {
    // Skip any leading whitespace
    while (mBuffer[mBufferPosition] == ' ' || mBuffer[mBufferPosition] == '\t') {
        ++mBufferPosition;
    }

    // Find the next line break boundary
    int32_t end = mBufferPosition;
    while (mBuffer[end] != '\n' && mBuffer[end] != '\0') {
        ++end;
    }

    // Return the section of the buffer starting from the current position and ending with the next line break boundary
    std::string section(mBuffer + mBufferPosition, end - mBufferPosition);
    mBufferPosition = end;
    return section;
}
