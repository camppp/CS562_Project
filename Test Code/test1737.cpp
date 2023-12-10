int calculateROIarea(int x, int y, int height) {
    // Calculate the area of the ROI
    if (height <= 0) {
        return 0;  // If height is non-positive, area is 0
    } else {
        return height * (x > 0 ? x : 0);  // Area = height * width
    }
}
