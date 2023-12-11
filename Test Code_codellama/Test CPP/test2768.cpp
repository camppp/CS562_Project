int findValueInBlob(const char* blob, int blobSize, char value) {
    for (int i = 0; i < blobSize; ++i) {
        if (blob[i] == value) {
            return i;
        }
    }
    return -1;
}
