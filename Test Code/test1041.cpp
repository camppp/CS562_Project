#include <vector>
#include <cmath>

// Define the resampling function
univector<fbase> resampleAudio(const univector<fbase>& audioData, int inputSamplingRate, int outputSamplingRate, double resamplingRatio, double resamplingPhase) {
    // Calculate the length of the resampled audio data
    size_t resampledLength = static_cast<size_t>(audioData.size() * outputSamplingRate / inputSamplingRate);

    // Initialize the resampled audio data vector
    univector<fbase> resampledAudio(resampledLength);

    // Perform resampling using linear interpolation
    for (size_t i = 0; i < resampledLength; ++i) {
        double index = i * static_cast<double>(inputSamplingRate) / outputSamplingRate;
        size_t leftIndex = static_cast<size_t>(std::floor(index));
        size_t rightIndex = static_cast<size_t>(std::ceil(index));

        // Perform linear interpolation
        if (rightIndex < audioData.size()) {
            double fraction = index - leftIndex;
            resampledAudio[i] = audioData[leftIndex] + (audioData[rightIndex] - audioData[leftIndex]) * fraction;
        } else {
            resampledAudio[i] = audioData[leftIndex];
        }
    }

    return resampledAudio;
}
