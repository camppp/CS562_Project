HRESULT GetRfc1766Tag(int Locale, wchar_t* pwszRfc1766, int nChar)
{
    int i;
    HRESULT hr = E_FAIL; // Assuming E_FAIL represents a failure code

    if (0 < nChar)
    {
        for (i = 0; i < g_cRfc1766; i++)
        {
            if (MimeRfc1766[i].LcId == Locale)
                break;
        }
        if (i < g_cRfc1766)
        {
            int tagLength = wcslen(MimeRfc1766[i].szRfc1766);
            if (tagLength < nChar)
            {
                wcscpy(pwszRfc1766, MimeRfc1766[i].szRfc1766);
                hr = S_OK;
            }
            else
            {
                wcsncpy(pwszRfc1766, MimeRfc1766[i].szRfc1766, nChar - 1);
                pwszRfc1766[nChar - 1] = L'\0'; // Ensure null-termination
                hr = E_BUFFER_TOO_SMALL; // Assuming E_BUFFER_TOO_SMALL represents a buffer too small error code
            }
        }
    }

    return hr;
}
