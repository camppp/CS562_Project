int processImage(int** mImage, int rows, int cols) {
    if (mImage == NULL) {
        return -1; // Return error code if image data is NULL
    }

    // Perform the specific operation on each pixel of the image
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Perform the required operation on mImage[i][j]
            // Example: mImage[i][j] = mImage[i][j] * 2; // Multiply each pixel value by 2
        }
    }

    return 0; // Return 0 to indicate successful processing
}
