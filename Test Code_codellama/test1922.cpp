c
void resizeImage(Image* img, int newWidth, int newHeight) {
    // Check if the new dimensions are valid
    if (newWidth <= 0 || newHeight <= 0) {
        return;
    }

    // Calculate the scaling factors for the x and y axes
    float xScale = (float)newWidth / img->width;
    float yScale = (float)newHeight / img->height;

    // Allocate memory for the new image data
    int* newData = (int*)malloc(newWidth * newHeight * sizeof(int));
    if (newData == NULL) {
        return;
    }

    // Resize the image data
    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            // Calculate the source pixel coordinates
            int srcX = (int)(x * xScale);
            int srcY = (int)(y * yScale);

            // Interpolate the pixel value
            float pixelValue = (float)img->data[srcY * img->width + srcX] * (1 - xScale) * (1 - yScale) +
                               (float)img->data[(srcY + 1) * img->width + srcX] * xScale * (1 - yScale) +
                               (float)img->data[srcY * img->width + (srcX + 1)] * (1 - xScale) * yScale +
                               (float)img->data[(srcY + 1) * img->width + (srcX + 1)] * xScale * yScale;

            // Store the interpolated pixel value in the new image data
            newData[y * newWidth + x] = (int)pixelValue;
        }
    }

    // Free the old image data
    free(img->data);

    // Update the image dimensions and data
    img->width = newWidth;
    img->height = newHeight;
    img->data = newData;
}
