#include "plug/plugid_t.hpp"
#include "plug/pluginsets_types.hpp"
#include "stl/map.hpp"
#include "stl/string.hpp"

namespace plug { class PluginMgr; }

namespace plug
{
    class PluginSettings
    {
    public:
        PluginSettings(const PluginMgr& plug_mgr);

        // Method to retrieve settings for a specific plugin
        const PluginSettingsType& getPluginSettings(const plugid_t& pluginId) const
        {
            auto it = pluginSettingsMap.find(pluginId);
            if (it != pluginSettingsMap.end()) {
                return it->second;
            } else {
                // Handle case when plugin settings are not found
                throw std::runtime_error("Plugin settings not found for the specified plugin ID");
            }
        }

    private:
        std::map<plugid_t, PluginSettingsType> pluginSettingsMap;
    };
}
