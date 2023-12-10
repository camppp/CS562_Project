#include <OpenEXR/half.h>
#include <OpenEXR/ImfRgba.h>
#include <OpenEXR/ImfRgbaFile.h>

float* ReadEXR(const char *name, int& xRes, int& yRes) {
    // Open the OpenEXR file
    Imf::RgbaInputFile file(name);

    // Get the image dimensions
    Imf::Box2i displayWindow = file.displayWindow();
    xRes = displayWindow.max.x - displayWindow.min.x + 1;
    yRes = displayWindow.max.y - displayWindow.min.y + 1;

    // Allocate memory for the pixel data
    float* pixels = new float[xRes * yRes * 4];

    // Read the pixel data
    file.setFrameBuffer(pixels, 1, xRes);
    file.readPixels(displayWindow.min.y, displayWindow.max.y);

    // Return the pixel data
    return pixels;
}
