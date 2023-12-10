pxMatrix rotateTextureMatrix(pxMatrix textureMatrix, float gRotateDelta, float gTextureRotate) {
    // Reset the matrix to an identity matrix
    textureMatrix.identity();

    // Apply a 2D rotation transformation by the given angle
    textureMatrix.rotate(gTextureRotate + gRotateDelta);

    // Return the updated texture matrix
    return textureMatrix;
}
