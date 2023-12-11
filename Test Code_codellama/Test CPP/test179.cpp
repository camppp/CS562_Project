bool ValidateTextureSize(int textureSize)
{
    return textureSize >= UICOMPONENT_MIN_TEXTURE_SIZE && textureSize <= UICOMPONENT_MAX_TEXTURE_SIZE;
}
