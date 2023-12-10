#include <iostream>
#include <unordered_map>

enum class BreakableType { JAR, VASE, CRATE, BARREL };

int getYAdjustment(BreakableType type) {
    std::unordered_map<BreakableType, int> adjustmentMap = {
        {BreakableType::JAR, -9},
        {BreakableType::VASE, -7},
        {BreakableType::CRATE, -12},
        {BreakableType::BARREL, -10}
    };

    return adjustmentMap[type];
}

int main() {
    // Test cases
    std::cout << "Adjustment for JAR: " << getYAdjustment(BreakableType::JAR) << std::endl;
    std::cout << "Adjustment for VASE: " << getYAdjustment(BreakableType::VASE) << std::endl;
    std::cout << "Adjustment for CRATE: " << getYAdjustment(BreakableType::CRATE) << std::endl;
    std::cout << "Adjustment for BARREL: " << getYAdjustment(BreakableType::BARREL) << std::endl;

    return 0;
}
