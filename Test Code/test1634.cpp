HRESULT GetDirect3DRMObject(DWORD i, IDirect3DRMObject** obj)
{
    HRESULT hr;
    IDirect3DRMObject* realobj = NULL;

    hr = m__dxj_Direct3dRMObjectArray->GetElement((DWORD)i, &realobj);
    if (FAILED(hr))
        return hr;

    *obj = realobj;
    return S_OK;
}
