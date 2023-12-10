D3D11_SHADER_RESOURCE_VIEW_DESC CreateShaderResourceViewDesc(const D3D11_TEXTURE1D_DESC& textureDesc)
{
    D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc;

    // Set the view dimension based on the texture type
    if (textureDesc.ArraySize > 1)
    {
        shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE1DARRAY;
    }
    else
    {
        shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE1D;
    }

    // Set the texture type
    shaderResourceViewDesc.Texture1DArray.MostDetailedMip = 0;
    shaderResourceViewDesc.Texture1DArray.MipLevels = -1;

    // Set the texture format
    shaderResourceViewDesc.Format = textureDesc.Format;

    // Set the texture flags
    shaderResourceViewDesc.Flags = 0;

    return shaderResourceViewDesc;
}
