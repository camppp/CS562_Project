#include <iostream>

template <typename T>
class Image {
    // Assume implementation for the Image class
};

template <typename T>
class VMatrix {
private:
    int w, h;

public:
    Image<T> *newOrReuse(Image<T> **reuse, int w, int h) const {
        if ((reuse) && (*reuse) && (w == (*reuse)->getW() && h == (*reuse)->getH())) {
            return *reuse;
        } else {
            if ((reuse) && (*reuse)) {
                delete *reuse;
            }
            *reuse = new Image<T>;
            (*reuse)->allocate(w, h);
            return *reuse;
        }
    }

    VMatrix() {
        w = h = 0;
    }
};

int main() {
    // Example usage
    VMatrix<RGBPixel> matrix;
    Image<RGBPixel> *reuseImage = nullptr;
    Image<RGBPixel> *newImage = matrix.newOrReuse(&reuseImage, 800, 600);
    // Use newImage for further processing
    return 0;
}
