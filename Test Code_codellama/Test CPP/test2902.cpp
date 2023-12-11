HRESULT CreateSolidColorBrush(ID2D1HwndRenderTarget* pRenderTarget, D2D1_COLOR_F color, ID2D1SolidColorBrush** pBrush)
{
    // Create a new solid color brush
    HRESULT hr = pRenderTarget->CreateSolidColorBrush(color, pBrush);

    // Check for errors
    if (FAILED(hr))
    {
        return hr;
    }

    // Set the brush properties
    (*pBrush)->SetOpacity(1.0f);
    (*pBrush)->SetColor(color);

    // Return the brush
    return S_OK;
}
