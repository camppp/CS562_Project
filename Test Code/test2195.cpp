java
public static int calculatePixelCount(int height, int width, int colorDepth) {
    return height * width * (1 << colorDepth);
}
