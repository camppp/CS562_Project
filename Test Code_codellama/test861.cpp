c
HRESULT GetRfc1766Tag(LCID Locale, WCHAR* pwszRfc1766, DWORD nChar)
{
    HRESULT hr = E_FAIL;
    int i;

    if (0 < nChar)
    {
        for (i = 0; i < g_cRfc1766; i++)
        {
            if (MimeRfc1766[i].LcId == Locale)
                break;
        }
        if (i < g_cRfc1766)
        {
            MLStrCpyNW(pwszRfc1766, MimeRfc1766[i].szRfc1766, nChar);
            hr = S_OK;
        }
    }

    return hr;
}
