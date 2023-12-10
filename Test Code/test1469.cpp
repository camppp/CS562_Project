#include <ImfRgbaFile.h>
#include <ImfArray.h>
#include <ImfNamespace.h>
#include <ImfRgba.h>

using namespace Imf;
using namespace Imath;

float* ReadEXR(const char *name, int& xRes, int& yRes) {
    RgbaInputFile file(name);
    Box2i dw = file.dataWindow();
    xRes = dw.max.x - dw.min.x + 1;
    yRes = dw.max.y - dw.min.y + 1;

    int numPixels = xRes * yRes;
    float* pixels = new float[numPixels * 4];

    Rgba* rgba = new Rgba[numPixels];
    file.setFrameBuffer(&rgba[0][0], 1, xRes);
    file.readPixels(dw.min.y, dw.max.y);

    for (int i = 0; i < numPixels; ++i) {
        pixels[4 * i] = rgba[i].r;
        pixels[4 * i + 1] = rgba[i].g;
        pixels[4 * i + 2] = rgba[i].b;
        pixels[4 * i + 3] = rgba[i].a;
    }

    delete[] rgba;
    return pixels;
}
