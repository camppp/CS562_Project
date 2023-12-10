#include <array>

int maxSupportedSIMDVersion(const std::array<uint32_t, 4>& regs) {
    int maxVersion = 0;
    for (int i = 0; i < 4; i++) {
        uint32_t reg = regs[i];
        if ((reg & 0x00000001) != 0) {
            maxVersion = std::max(maxVersion, 1);
        }
        if ((reg & 0x00000040) != 0) {
            maxVersion = std::max(maxVersion, 2);
        }
        if ((reg & 0x00000800) != 0) {
            maxVersion = std::max(maxVersion, 3);
        }
        if ((reg & 0x10000000) != 0) {
            maxVersion = std::max(maxVersion, 4);
        }
    }
    return maxVersion;
}
