HRESULT CreateSolidColorBrush(ID2D1HwndRenderTarget* pRenderTarget, D2D1_COLOR_F color, ID2D1SolidColorBrush** pBrush) {
    if (pRenderTarget == nullptr || pBrush == nullptr) {
        return E_INVALIDARG; // Invalid arguments
    }

    HRESULT hr = pRenderTarget->CreateSolidColorBrush(color, pBrush);
    return hr;
}
