#include <vector>
#include <algorithm>

namespace musher {
    namespace core {
        void SquareWindowing(std::vector<double>& input, size_t windowSize) {
            // Ensure window size is within the range of the input signal
            windowSize = std::min(windowSize, input.size());

            // Apply square windowing to the input signal
            for (size_t i = 0; i < windowSize; ++i) {
                input[i] *= (i < windowSize) ? 1.0 : 0.0;
            }
        }
    }  // namespace core
}  // namespace musher
