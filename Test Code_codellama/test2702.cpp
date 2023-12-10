bool CheckResult(HRESULT hr, ID3DBlob* blob, ID3DBlob* errorblob)
{
    if (hr == S_OK && blob != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
