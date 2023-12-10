#include <iostream>
#include <string>

class RegistryManager {
public:
    static bool IsValidRegistryHive(int hive) {
        return hive == DynData || hive == LocalMachine;
    }

    static void SetDynData(int hive) {
        if (IsValidRegistryHive(hive)) {
            _set_DynData(hive);
        } else {
            std::cout << "Invalid registry hive value: " << hive << std::endl;
        }
    }

    static int GetDynData() {
        return _get_DynData();
    }

    static int GetLocalMachine() {
        return LocalMachine;
    }

private:
    static constexpr int DynData = -2147483642;
    static constexpr int LocalMachine = 2147483647;

    static void _set_DynData(int hive) {
        // Implement your own logic to set the registry hive value
    }

    static int _get_DynData() {
        // Implement your own logic to get the registry hive value
    }
};

int main() {
    RegistryManager::SetDynData(RegistryManager::DynData);
    std::cout << "DynData: " << RegistryManager::GetDynData() << std::endl;
    std::cout << "LocalMachine: " << RegistryManager::GetLocalMachine() << std::endl;
    return 0;
}
