#include <iostream>
#include <string>
#include <unordered_map>

// Assume a map to store the enabled features for each plugin
std::unordered_map<XPLMPluginID, std::unordered_map<std::string, bool>> pluginFeatures;

void XPLMEnableFeature(const char *inFeature, int inEnable) {
    // Assume inPlugin is the ID of the current plugin
    XPLMPluginID inPlugin = GetCurrentPluginID();

    // Enable or disable the feature for the current plugin
    pluginFeatures[inPlugin][inFeature] = (inEnable != 0);

    // Optionally, notify the simulation software about the feature change
    NotifyFeatureChange(inPlugin, inFeature, inEnable);
}
