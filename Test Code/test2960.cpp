int calculateImageSize(int width, int height, int bpp) {
    if (bpp != 24) {
        PrintError("Unsupported color depth: " + bpp + "bpp");
        return -1;
    }
    return width * height * (bpp / 8);
}
