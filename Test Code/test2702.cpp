bool CheckResult(HRESULT hr, ComPtr<ID3DBlob> compiledShaderBlob, ComPtr<ID3DBlob> errorBlob) {
    if (SUCCEEDED(hr) && compiledShaderBlob != nullptr) {
        return true;
    } else {
        return false;
    }
}
