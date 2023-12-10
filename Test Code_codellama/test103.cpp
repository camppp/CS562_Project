BOOL COMInit()
{
    HRESULT coResult = CoInitializeEx(NULL, COINIT_MULTITHREADED);
    if (coResult == RPC_E_CHANGED_MODE)
    {
        return TRUE;
    }
    else if (SUCCEEDED(coResult))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
