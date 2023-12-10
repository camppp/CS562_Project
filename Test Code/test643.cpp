#include <Windows.h>
#include <iostream>

bool setRegistryValue(HKEY hKey, const char* subKey, const char* valueName, DWORD valueType, const BYTE* valueData) {
    LONG result;
    HKEY keyHandle;

    result = RegOpenKeyExA(hKey, subKey, 0, KEY_SET_VALUE, &keyHandle);
    if (result != ERROR_SUCCESS) {
        std::cerr << "Error opening registry key: " << result << std::endl;
        return false;
    }

    result = RegSetValueExA(keyHandle, valueName, 0, valueType, valueData, sizeof(valueData));
    if (result != ERROR_SUCCESS) {
        std::cerr << "Error setting registry value: " << result << std::endl;
        RegCloseKey(keyHandle);
        return false;
    }

    RegCloseKey(keyHandle);
    return true;
}

int main() {
    HKEY hKey = HKEY_CURRENT_USER;
    const char* subKey = "Software\\MyApp";
    const char* valueName = "Version";
    DWORD valueType = REG_SZ;
    const BYTE valueData[] = "1.0";

    if (setRegistryValue(hKey, subKey, valueName, valueType, valueData)) {
        std::cout << "Registry value set successfully." << std::endl;
    } else {
        std::cerr << "Failed to set registry value." << std::endl;
    }

    return 0;
}
