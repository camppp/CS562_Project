#include <iostream>
#include <unordered_map>

template <typename T>
class FeatureFlagManager {
public:
    void RegisterFeature(const std::string& featureName, bool defaultEnablement) {
        features_[featureName] = defaultEnablement;
    }

    void RegisterFeatureParam(const std::string& featureName, const std::string& paramName, T defaultValue) {
        featureParams_[featureName + paramName] = defaultValue;
    }

    bool IsFeatureEnabled(const std::string& featureName) const {
        auto it = features_.find(featureName);
        if (it != features_.end()) {
            return it->second;
        }
        return false;  // Feature not found, default to disabled.
    }

    T GetFeatureParamValue(const std::string& featureName, const std::string& paramName) const {
        auto it = featureParams_.find(featureName + paramName);
        if (it != featureParams_.end()) {
            return it->second;
        }
        return T();  // Parameter not found, return default-constructed value.
    }

private:
    std::unordered_map<std::string, bool> features_;
    std::unordered_map<std::string, T> featureParams_;
};

int main() {
    FeatureFlagManager<int> manager;
    manager.RegisterFeature("UsernameFirstFlowFallbackCrowdsourcing", false);
    manager.RegisterFeatureParam("UsernameFirstFlowFallbackCrowdsourcing", "migration_version", 0);

    std::cout << "Feature enabled: " << manager.IsFeatureEnabled("UsernameFirstFlowFallbackCrowdsourcing") << std::endl;
    std::cout << "Migration version: " << manager.GetFeatureParamValue("UsernameFirstFlowFallbackCrowdsourcing", "migration_version") << std::endl;

    return 0;
}
