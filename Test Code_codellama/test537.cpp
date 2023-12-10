void VMatrix::newOrReuse(Image<RGBPixel>*& reuse, int w, int h) {
    if (reuse != nullptr && reuse->getWidth() == w && reuse->getHeight() == h) {
        // Reuse the existing image
        return;
    }

    // Create a new image
    Image<RGBPixel>* newImage = new Image<RGBPixel>(w, h);

    // Deallocate the existing image if it exists
    if (reuse != nullptr) {
        delete reuse;
    }

    // Set the new image as the reuse pointer
    reuse = newImage;
}
