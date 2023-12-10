#include <iostream>
#include <Windows.h>

class RegistryManager {
public:
    static bool IsValidRegistryHive(int value) {
        return (value == HKEY_CLASSES_ROOT ||
                value == HKEY_CURRENT_USER ||
                value == HKEY_LOCAL_MACHINE ||
                value == HKEY_USERS ||
                value == HKEY_CURRENT_CONFIG ||
                value == -2147483642); // DynData value
    }

    static int GetDynData() {
        return -2147483642; // DynData value
    }

    static void SetDynData(int value) {
        // Set the DynData value
        // Example: _set_DynData(value);
    }

    static int GetLocalMachine() {
        return HKEY_LOCAL_MACHINE; // LocalMachine value
    }
};

int main() {
    int dynDataValue = RegistryManager::GetDynData();
    std::cout << "DynData value: " << dynDataValue << std::endl;

    int localMachineValue = RegistryManager::GetLocalMachine();
    std::cout << "LocalMachine value: " << localMachineValue << std::endl;

    int testValue = -2147483642; // Example test value
    std::cout << "Is " << testValue << " a valid registry hive value? " << std::boolalpha << RegistryManager::IsValidRegistryHive(testValue) << std::endl;

    return 0;
}
