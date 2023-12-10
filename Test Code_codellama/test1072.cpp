std::tuple<int, int, int> getHighestResolutionMode(const std::vector<std::tuple<int, int, int>>& videoModes) {
    // Initialize the highest resolution and refresh rate to the first mode in the vector
    int highestResolution = std::get<0>(videoModes[0]);
    int highestRefreshRate = std::get<2>(videoModes[0]);

    // Iterate over the remaining modes and compare their resolution and refresh rate to the current highest
    for (int i = 1; i < videoModes.size(); i++) {
        int resolution = std::get<0>(videoModes[i]);
        int refreshRate = std::get<2>(videoModes[i]);
        if (resolution > highestResolution || (resolution == highestResolution && refreshRate > highestRefreshRate)) {
            highestResolution = resolution;
            highestRefreshRate = refreshRate;
        }
    }

    // Return the mode with the highest resolution and refresh rate
    return {highestResolution, highestRefreshRate};
}
