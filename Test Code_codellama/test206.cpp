bool isTextureProjectionModeParallel()
{
    bool bParallelY = false;

    // Get the texture projection mode along the Y-axis
    ::com::sun::star::drawing::TextureProjectionMode_PARALLEL yProjectionMode = getTextureProjectionY();

    // Check if the projection mode is parallel
    if (yProjectionMode == ::com::sun::star::drawing::TextureProjectionMode_PARALLEL)
    {
        bParallelY = true;
    }

    return bParallelY;
}
