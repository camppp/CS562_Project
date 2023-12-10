bool isTextureProjectionModeParallel() {
    // Assuming getSdr3DObjectAttribute() and getTextureProjectionY() are accessible

    // Retrieve the texture projection mode along the Y-axis
    const auto textureProjectionY = getSdr3DObjectAttribute().getTextureProjectionY();

    // Check if the texture projection mode along the Y-axis is parallel
    const bool isParallelY = (textureProjectionY == ::com::sun::star::drawing::TextureProjectionMode_PARALLEL);

    return isParallelY;
}
