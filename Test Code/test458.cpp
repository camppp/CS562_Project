D3D11_SHADER_RESOURCE_VIEW_DESC CreateShaderResourceViewDesc(const D3D11_TEXTURE1D_DESC& textureDesc)
{
    D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc = {};

    if (textureDesc.ArraySize > 1) // 1D array texture
    {
        shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE1DARRAY;
        shaderResourceViewDesc.Texture1DArray.MostDetailedMip = 0;
        shaderResourceViewDesc.Texture1DArray.MipLevels = -1;
        shaderResourceViewDesc.Texture1DArray.FirstArraySlice = 0;
        shaderResourceViewDesc.Texture1DArray.ArraySize = textureDesc.ArraySize;
    }
    else // 1D texture
    {
        shaderResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE1D;
        shaderResourceViewDesc.Texture1D.MostDetailedMip = 0;
        shaderResourceViewDesc.Texture1D.MipLevels = -1;
    }

    return shaderResourceViewDesc;
}
