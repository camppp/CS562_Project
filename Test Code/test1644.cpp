#include "FuzzCommon.h"

class Fuzz {
public:
    void next(SkRegion* region) {
        FuzzNiceRegion(this, region, 10);
    }

    void nextRange(float* f, float min, float max) {
        // Generate a random value within the specified range
        float fuzzedValue = min + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(max-min)));
        
        // Apply the fuzzed value to the input pointer
        *f = fuzzedValue;
    }
};
