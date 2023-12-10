#include "FuzzCommon.h"

class Fuzz {
public:
    void next(SkRegion* region) {
        FuzzNiceRegion(this, region, 10);
    }

    void nextRange(float* f, float min, float max) {
        *f = min + (max - min) * (float)rand() / (float)RAND_MAX;
    }
};
