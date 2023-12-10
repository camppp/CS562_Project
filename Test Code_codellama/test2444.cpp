void CopyImage(const Image& src, const Image& dst, const Position& pos) {
    // Calculate the total number of bytes to be copied
    int totalBytes = src.width * src.height * 3;

    // Calculate the starting position in the destination buffer
    int dstStartX = pos.x;
    int dstStartY = pos.y;

    // Calculate the ending position in the destination buffer
    int dstEndX = dstStartX + src.width;
    int dstEndY = dstStartY + src.height;

    // Check if the copy operation exceeds the boundaries of the destination buffer
    if (dstEndX > dst.width || dstEndY > dst.height) {
        // Handle the case where the source image extends beyond the boundaries of the destination buffer
        // ...
    }

    // Copy the image data
    for (int y = 0; y < src.height; y++) {
        for (int x = 0; x < src.width; x++) {
            // Calculate the source and destination positions
            int srcPos = (y * src.width + x) * 3;
            int dstPos = (dstStartY + y) * dst.width * 3 + (dstStartX + x) * 3;

            // Copy the pixel data
            dst.data[dstPos] = src.data[srcPos];
            dst.data[dstPos + 1] = src.data[srcPos + 1];
            dst.data[dstPos + 2] = src.data[srcPos + 2];
        }
    }
}
