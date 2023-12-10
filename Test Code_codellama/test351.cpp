#include <string>
#include <unordered_map>
#include <utility>

template <typename T>
class FeatureFlagManager {
public:
    void RegisterFeature(const std::string& featureName, bool defaultEnablement) {
        features_[featureName] = defaultEnablement;
    }

    void RegisterFeatureParam(const std::string& featureName, const std::string& paramName, T defaultValue) {
        featureParams_[featureName][paramName] = defaultValue;
    }

    bool IsFeatureEnabled(const std::string& featureName) const {
        return features_.find(featureName) != features_.end() && features_.at(featureName);
    }

    T GetFeatureParamValue(const std::string& featureName, const std::string& paramName) const {
        if (featureParams_.find(featureName) != featureParams_.end() && featureParams_.at(featureName).find(paramName) != featureParams_.at(featureName).end()) {
            return featureParams_.at(featureName).at(paramName);
        }
        return T();
    }

private:
    std::unordered_map<std::string, bool> features_;
    std::unordered_map<std::string, std::unordered_map<std::string, T>> featureParams_;
};
