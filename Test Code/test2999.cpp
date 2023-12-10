#include <iostream>
#include <vector>

class MetadataManager {
private:
    std::vector<int> _internal_metadata_;

public:
    // Custom swap function for MetadataManager
    void CustomSwap(MetadataManager& other) {
        _internal_metadata_.swap(other._internal_metadata_);
    }

    // Method to retrieve metadata from a protobuf file
    std::vector<int> GetMetadata() const {
        // Placeholder code to retrieve metadata from protobuf file
        // For demonstration purposes, returning a modified metadata vector
        std::vector<int> retrievedMetadata = {1, 2, 3, 4, 5};
        return retrievedMetadata;
    }
};

int main() {
    MetadataManager manager1;
    manager1.GetMetadata();  // Placeholder call to GetMetadata method

    MetadataManager manager2;
    manager2.GetMetadata();  // Placeholder call to GetMetadata method

    // Swap the internal metadata vectors of manager1 and manager2
    manager1.CustomSwap(manager2);

    return 0;
}
