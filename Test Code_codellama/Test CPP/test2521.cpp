c
HRESULT RetrieveAndCombineCapabilities(ISource* pSeek, DWORD* pCapabilities)
{
    // Retrieve the capabilities from the source
    DWORD capsThis = 0;
    HRESULT hr = pSeek->GetCapabilities(&capsThis);
    if (FAILED(hr))
    {
        return hr;
    }

    // Combine the capabilities with the existing ones
    *pCapabilities |= capsThis;

    return S_OK;
}
