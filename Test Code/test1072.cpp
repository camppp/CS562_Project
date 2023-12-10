#include <vector>
#include <tuple>

std::tuple<int, int, int> getHighestResolutionMode(const std::vector<std::tuple<int, int, int>>& videoModes) {
    std::tuple<int, int, int> highestMode = videoModes[0];  // Initialize with the first mode
    for (const auto& mode : videoModes) {
        if (std::get<0>(mode) > std::get<0>(highestMode) ||  // Check for higher resolution
            (std::get<0>(mode) == std::get<0>(highestMode) && std::get<1>(mode) > std::get<1>(highestMode)) ||  // Check for same resolution but higher refresh rate
            (std::get<0>(mode) == std::get<0>(highestMode) && std::get<1>(mode) == std::get<1>(highestMode) && std::get<2>(mode) > std::get<2>(highestMode))) {  // Check for same resolution and refresh rate but higher refresh rate
            highestMode = mode;  // Update highest mode
        }
    }
    return highestMode;
}
