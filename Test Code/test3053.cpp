FBXTexture^ ArcManagedFBX::FBXLight::GetShadowTexture()
{
    // Assuming GetFBXLight() returns the current light source
    return gcnew FBXTexture(this->GetFBXLight()->GetShadowTexture());
}
