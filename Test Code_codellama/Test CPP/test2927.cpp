#include <vector>
#include <cstdint>

class MSE {
private:
    double loss;

public:
    // Constructor and other methods are not shown for brevity

    // Compute the derivative of the MSE loss function
    std::vector<double> deriv(const std::vector<double>& prediction, int8_t expected_int) const {
        // Here we compute the one-hot encoding
        uint output_layer_size = prediction.size();
        std::vector<double> expected_vector(output_layer_size, 0.0);
        expected_vector[expected_int] = 1.0;

        // Compute the derivative of the MSE loss function
        std::vector<double> derivative(output_layer_size, 0.0);
        for (uint i = 0; i < output_layer_size; ++i) {
            derivative[i] = 2 * (prediction[i] - expected_vector[i]) / output_layer_size;
        }

        return derivative;
    }
};
