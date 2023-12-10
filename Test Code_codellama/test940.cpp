float calculateSurfaceArea(float length, float width, float height)
{
    // Calculate the surface area of each face
    float faceArea1 = length * width;
    float faceArea2 = width * height;
    float faceArea3 = length * height;

    // Calculate the total surface area by summing the areas of all faces
    float totalSurfaceArea = faceArea1 + faceArea2 + faceArea3;

    return totalSurfaceArea;
}
