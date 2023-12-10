#include <iostream>
#include <cmath>

class SfxrNode {
public:
    SfxrNode() {}

    void setStartFrequencyInHz(float value) {
        startFrequencyInHz = value;
    }

    void setVibratoSpeedInHz(float value) {
        vibratoSpeedInHz = value;
    }

    float getStartFrequencyInHz() {
        return startFrequencyInHz;
    }

    float getVibratoSpeedInHz() {
        return vibratoSpeedInHz;
    }

private:
    float startFrequencyInHz = 0.0f;
    float vibratoSpeedInHz = 0.0f;
};

DART_EXPORT void SfxrNode_setStartFrequencyInHz(int nodeId, float value) {
    auto node = std::static_pointer_cast<SfxrNode>(getNode(nodeId));
    if(node) node->setStartFrequencyInHz(value);
}

DART_EXPORT void SfxrNode_setVibratoSpeedInHz(int nodeId, float value) {
    auto node = std::static_pointer_cast<SfxrNode>(getNode(nodeId));
    if(node) node->setVibratoSpeedInHz(value);
}
