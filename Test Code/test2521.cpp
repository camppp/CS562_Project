HRESULT RetrieveAndCombineCapabilities(ISource* pSeek, DWORD* pCapabilities) {
    if (pSeek == nullptr || pCapabilities == nullptr) {
        return E_INVALIDARG; // Invalid arguments
    }

    DWORD caps = 0;
    HRESULT hr = pSeek->GetCapabilities(&caps);
    if (SUCCEEDED(hr)) {
        *pCapabilities |= caps;
        return S_OK; // Success
    } else {
        return hr; // Propagate the error
    }
}
