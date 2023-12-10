float calculateSurfaceArea(float length, float width, float height) {
    // Calculate the surface area of the 3D object
    float area = 2 * (length * width + width * height + height * length);
    return area;
}
