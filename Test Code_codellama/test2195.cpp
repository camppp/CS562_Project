#include <iostream>

int calculatePixelCount(int height, int width, int colorDepth) {
    return height * width * (1 << colorDepth);
}

int main() {
    int height = 100;
    int width = 200;
    int colorDepth = 8;

    int totalPixels = calculatePixelCount(height, width, colorDepth);

    std::cout << "Total pixels: " << totalPixels << std::endl;

    return 0;
}
