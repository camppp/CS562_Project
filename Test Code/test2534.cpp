#include <TooN/TooN.h>  // Include the necessary library for TooN::SE3<double>

class Predictor {
private:
    TooN::SE3<double> droneToGlobal;
    TooN::SE3<double> droneToLocal;

public:
    // Other methods and constructors

    TooN::SE3<double> calculateCombinedTransformations() {
        // Calculate the combined transformation matrix
        return droneToGlobal * droneToLocal;
    }
};
