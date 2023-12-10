#include <memory>

class SfxrNode {
private:
    float startFrequencyInHz;
    float vibratoSpeedInHz;

public:
    void setStartFrequencyInHz(float value) {
        startFrequencyInHz = value;
    }

    void setVibratoSpeedInHz(float value) {
        vibratoSpeedInHz = value;
    }

    // Add any other necessary methods or constructors here

    // Example of using shared_ptr for memory management
    static std::shared_ptr<SfxrNode> getNode(int nodeId) {
        // Implementation to retrieve the SfxrNode based on nodeId
        // Return a shared_ptr to the retrieved SfxrNode
    }
};
