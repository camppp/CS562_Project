#include <vector>
#include <memory>

class Feature {
    // Implementation details not provided
};

class FeatureCollection {
private:
    std::vector<std::shared_ptr<Feature>> _features;

public:
    // Constructor to initialize the collection with a vector of shared pointers to Feature objects
    FeatureCollection(std::vector<std::shared_ptr<Feature>> features) :
        _features(std::move(features))
    {
    }

    // Destructor to release any allocated resources
    ~FeatureCollection() {
        // Automatically releases the shared pointers to Feature objects
    }

    // Method to add a new feature to the collection
    void addFeature(std::shared_ptr<Feature> feature) {
        _features.push_back(feature);
    }

    // Method to remove a feature from the collection
    void removeFeature(std::shared_ptr<Feature> feature) {
        _features.erase(std::remove(_features.begin(), _features.end(), feature), _features.end());
    }

    // Method to retrieve all features in the collection
    std::vector<std::shared_ptr<Feature>> getAllFeatures() const {
        return _features;
    }
};
