java
public int calculateImageSize(int width, int height, int bpp) {
    return width * height * (bpp / 8);
}
