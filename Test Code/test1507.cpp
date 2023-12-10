#include <iostream>
#include <cctype>

bool ValidateLicenseKey(const std::string& FromUser) {
    for (size_t Buffer_Offset = 0; Buffer_Offset < FromUser.size() / 2; Buffer_Offset++) {
        const char L1 = FromUser[Buffer_Offset * 2];
        const char L2 = FromUser[Buffer_Offset * 2 + 1];
        if (!((std::isxdigit(L1)) && (std::isxdigit(L2)))) {
            std::cerr << "Invalid characters in license key." << std::endl;
            return false;
        }
    }
    return true;
}
