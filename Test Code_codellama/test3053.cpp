FBXTexture^ ArcManagedFBX::FBXLight::GetShadowTexture()
{
    // Check if the light source has a shadow texture
    if (m_shadowTexture != nullptr)
    {
        // Return the shadow texture
        return m_shadowTexture;
    }
    else
    {
        // If the light source does not have a shadow texture, return null
        return nullptr;
    }
}
