#include <windows.h>

int LoadStringResource(HINSTANCE hInst, LPCSTR lpszName, UINT nID, LPSTR lpszBuf, int nMaxBuf)
{
    // Find the resource
    HRSRC hRes = FindResourceA(hInst, lpszName, RT_STRING);
    if (!hRes)
    {
        // Resource not found
        return 0;
    }

    // Load the resource
    HGLOBAL hGlobal = LoadResource(hInst, hRes);
    if (!hGlobal)
    {
        // Resource not loaded
        return 0;
    }

    // Get the resource size
    DWORD dwSize = SizeofResource(hInst, hRes);
    if (dwSize == 0)
    {
        // Resource size is zero
        return 0;
    }

    // Copy the resource to the buffer
    LPSTR lpszResource = (LPSTR)LockResource(hGlobal);
    if (!lpszResource)
    {
        // Resource not locked
        return 0;
    }

    // Check if the buffer is large enough to hold the resource
    if (nMaxBuf < dwSize)
    {
        // Buffer is too small
        return 0;
    }

    // Copy the resource to the buffer
    memcpy(lpszBuf, lpszResource, dwSize);

    // Unlock the resource
    UnlockResource(hGlobal);

    // Return the length of the loaded string
    return dwSize;
}
