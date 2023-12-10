#include <memory>
#include <vector>

class FeatureCollection {
public:
    FeatureCollection(std::vector<std::shared_ptr<Feature>> features) {
        for (auto& feature : features) {
            this->features.push_back(feature);
        }
    }

    ~FeatureCollection() {
        for (auto& feature : features) {
            feature.reset();
        }
    }

    void addFeature(std::shared_ptr<Feature> feature) {
        features.push_back(feature);
    }

    void removeFeature(std::shared_ptr<Feature> feature) {
        auto it = std::find(features.begin(), features.end(), feature);
        if (it != features.end()) {
            features.erase(it);
        }
    }

    std::vector<std::shared_ptr<Feature>> getAllFeatures() const {
        return features;
    }

private:
    std::vector<std::shared_ptr<Feature>> features;
};
