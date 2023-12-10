c
int processImage(int** mImage, int rows, int cols) {
    if (mImage == NULL) {
        return -1; // Error code indicating absence of image data
    }

    // Perform required processing on the image data
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Perform operation on each pixel
            mImage[i][j] = mImage[i][j] * 2;
        }
    }

    return 0; // Successful processing
}
