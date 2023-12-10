int findValueInBlob(const char* blob, int blobSize, char value) {
    for (int i = 0; i < blobSize; ++i) {
        if (blob[i] == value) {
            return i;  // Return the position of the first occurrence of the value
        }
    }
    return -1;  // Return -1 if the value is not found in the blob
}
