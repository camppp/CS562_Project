#include <TooN/SE3.h>

class Predictor {
public:
    TooN::SE3<double> droneToGlobal;
    TooN::SE3<double> droneToLocal;

    TooN::SE3<double> calculateCombinedTransformations() {
        return droneToGlobal * droneToLocal;
    }
};
