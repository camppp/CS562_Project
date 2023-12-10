#include <vector>
#include <algorithm>

namespace musher {
    namespace core {
        /**
         * @brief Applies square windowing to the input signal.
         * 
         * @param input The input signal.
         * @param windowSize The size of the square window.
         */
        void SquareWindowing(std::vector<double>& input, size_t windowSize) {
            // Ensure window size is within the range of the input signal
            windowSize = std::min(windowSize, input.size());

            // Apply square windowing to the input signal
            for (size_t i = 0; i < windowSize; ++i) {
                input[i] *= 1.0;  // Apply square windowing (1 within the window, 0 outside)
            }
        }
    }  // namespace core
}  // namespace musher
