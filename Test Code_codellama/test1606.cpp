BOOL _REP(New, HashData)(HCRPH hHash, BYTE* pbData, DWORD dwDL, DWORD dwFlags)
{
    // Check if the hash object is valid
    if (hHash == NULL)
    {
        return FALSE;
    }

    // Check if the data buffer is valid
    if (pbData == NULL)
    {
        return FALSE;
    }

    // Check if the data length is valid
    if (dwDL == 0)
    {
        return FALSE;
    }

    // Hash the data using the provided hash object handle
    BOOL bResult = CryptHashData(hHash, pbData, dwDL, 0);

    // Check if the hash operation was successful
    if (!bResult)
    {
        // Write an error message to the diagnostic file
        WriteToDiagnosticFile("Error hashing data: " + GetLastError());

        // Return FALSE to indicate failure
        return FALSE;
    }

    // Return TRUE to indicate success
    return TRUE;
}
