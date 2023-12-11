#include <vector>
#include <cmath>

using namespace std;

// Define the resampler object
class Resampler {
public:
    Resampler(int inputSamplingRate, int outputSamplingRate, double resamplingRatio, double resamplingPhase) {
        // Initialize the resampler object with the input and output sampling rates,
        // the resampling ratio, and the resampling phase
        this->inputSamplingRate = inputSamplingRate;
        this->outputSamplingRate = outputSamplingRate;
        this->resamplingRatio = resamplingRatio;
        this->resamplingPhase = resamplingPhase;
    }

    // Resample the audio data
    univector<fbase> resample(const univector<fbase>& audioData) {
        // Initialize the output vector
        univector<fbase> resampledAudioData(outputSamplingRate);

        // Resample the audio data
        for (int i = 0; i < audioData.size(); i++) {
            // Calculate the input sample index
            int inputSampleIndex = i * inputSamplingRate / outputSamplingRate;

            // Calculate the output sample index
            int outputSampleIndex = i * outputSamplingRate / inputSamplingRate;

            // Calculate the resampled audio data
            resampledAudioData[outputSampleIndex] = audioData[inputSampleIndex] * resamplingRatio + resamplingPhase;
        }

        return resampledAudioData;
    }

private:
    int inputSamplingRate;
    int outputSamplingRate;
    double resamplingRatio;
    double resamplingPhase;
};

// Implement the resampling function
univector<fbase> resampleAudio(const univector<fbase>& audioData, int inputSamplingRate, int outputSamplingRate, double resamplingRatio, double resamplingPhase) {
    // Create a resampler object
    Resampler resampler(inputSamplingRate, outputSamplingRate, resamplingRatio, resamplingPhase);

    // Resample the audio data
    return resampler.resample(audioData);
}
