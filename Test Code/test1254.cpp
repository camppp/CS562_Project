#include <iostream>

// Define the pxMatrix class with identity and rotate methods
class pxMatrix {
public:
    void identity() {
        // Implementation to reset the matrix to an identity matrix
    }

    void rotate(float angle) {
        // Implementation to apply a 2D rotation transformation by the given angle
    }
};

// Function to rotate the texture matrix
pxMatrix rotateTextureMatrix(pxMatrix textureMatrix, float gRotateDelta, float& gTextureRotate) {
    // Reset the texture matrix to an identity matrix
    textureMatrix.identity();

    // Apply the 2D rotation transformation by the current rotation angle increment
    textureMatrix.rotate(gTextureRotate += gRotateDelta);

    return textureMatrix;
}

int main() {
    // Example usage of the rotateTextureMatrix function
    pxMatrix textureMatrix;
    float gRotateDelta = 0.1f;  // Example rotation angle increment
    float gTextureRotate = 0.0f;  // Example initial rotation angle

    // Rotate the texture matrix and update the rotation angle
    textureMatrix = rotateTextureMatrix(textureMatrix, gRotateDelta, gTextureRotate);

    // Output the updated texture matrix
    std::cout << "Updated Texture Matrix: " << std::endl;
    // Output the updated texture matrix elements

    return 0;
}
