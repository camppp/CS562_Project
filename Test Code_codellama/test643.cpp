#include <Windows.h>

void setRegistryValue(HKEY hKey, const char* subKey, const char* valueName, DWORD valueType, const BYTE* valueData)
{
    // Open the subkey
    HKEY subKeyHandle;
    LONG result = RegOpenKeyExA(hKey, subKey, 0, KEY_WRITE, &subKeyHandle);
    if (result != ERROR_SUCCESS)
    {
        // Handle error
        return;
    }

    // Set the value
    result = RegSetValueExA(subKeyHandle, valueName, 0, valueType, valueData, (DWORD)strlen(valueData));
    if (result != ERROR_SUCCESS)
    {
        // Handle error
        RegCloseKey(subKeyHandle);
        return;
    }

    // Close the subkey
    RegCloseKey(subKeyHandle);
}
