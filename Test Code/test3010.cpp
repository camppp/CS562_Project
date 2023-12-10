Image::Format ToggleAlphaChannel(Image& img) {
    Image::Format currentFormat = img.GetFormat();
    switch (currentFormat) {
        case Image::RGB:
            img.SetFormat(Image::RGBA);
            return Image::RGBA;
        case Image::RGBA:
            img.SetFormat(Image::RGB);
            return Image::RGB;
        default:
            // For other formats like Grayscale and GrayscaleA, no change is made
            return currentFormat;
    }
}
