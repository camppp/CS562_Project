class DensityManager {
public:
    DensityManager() {}

    void addResourceConfigValue(const std::unique_ptr<ResourceConfigValue>& config_value) {
        // Check if the config value is already in the map
        if (config_claimed_map.find(config_value.get()) != config_claimed_map.end()) {
            return;
        }

        // Add the config value to the map
        config_claimed_map[config_value.get()] = false;

        // Create a bucket for this density-dependent config
        density_groups[CopyWithoutDensity(config_value->config)] = config_value;
    }

    ConfigDensityGroups getDensityGroups() {
        return density_groups;
    }

private:
    ConfigClaimedMap config_claimed_map;
    ConfigDensityGroups density_groups;
};
