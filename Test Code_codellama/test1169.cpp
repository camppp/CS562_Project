#include <map>
#include <string>

class PluginMgr;

class PluginSettings {
public:
    PluginSettings(PluginMgr& pluginMgr);
    ~PluginSettings();

    // Retrieve the settings for a specific plugin
    std::string getPluginSettings(plugid_t pluginId);

private:
    // Map to store the plugin settings
    std::map<plugid_t, std::string> pluginSettings;

    // Reference to the PluginMgr object
    PluginMgr& pluginMgr;
};

PluginSettings::PluginSettings(PluginMgr& pluginMgr) : pluginMgr(pluginMgr) {
    // Initialize the plugin settings map
    pluginSettings.clear();
}

PluginSettings::~PluginSettings() {
    // Clear the plugin settings map
    pluginSettings.clear();
}

std::string PluginSettings::getPluginSettings(plugid_t pluginId) {
    // Check if the plugin settings are already stored
    if (pluginSettings.find(pluginId) != pluginSettings.end()) {
        return pluginSettings[pluginId];
    }

    // Retrieve the plugin settings from the PluginMgr object
    std::string settings = pluginMgr.getPluginSettings(pluginId);

    // Store the plugin settings in the map
    pluginSettings[pluginId] = settings;

    return settings;
}
