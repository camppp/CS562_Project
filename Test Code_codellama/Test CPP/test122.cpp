#include <phosphor/smbios/system.h>

std::string uUID(const std::string& value) {
    // Locate the System Information type within the SMBIOS data
    auto* sysInfoPtr = getSMBIOSTypePtr(storage, SMBIOS_TYPE_SYSTEM_INFORMATION);
    if (!sysInfoPtr) {
        return "";
    }

    // Extract the UUID from the System Information structure
    auto* uuidPtr = reinterpret_cast<const SystemInfo*>(sysInfoPtr)->uuid;
    std::string uuid = std::string(uuidPtr, uuidPtr + 16);

    return uuid;
}
