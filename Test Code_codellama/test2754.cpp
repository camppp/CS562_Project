#include <JuceHeader.h>

class VDspFFT
{
public:
    VDspFFT(int numSamples)
    {
        // Initialize the FFT with the given audio sample buffer
        fft.setup(numSamples, 0, nullptr);
    }

    ~VDspFFT()
    {
        // Clean up the FFT resources
        fft.clear();
    }

    void performFFT(const AudioSampleBuffer& buffer)
    {
        // Perform the FFT operation on the given audio sample buffer
        fft.perform(buffer);
    }

    void retrieveResults(AudioSampleBuffer& results)
    {
        // Retrieve the results of the FFT operation
        fft.getResult(results);
    }

private:
    // FFT object
    JUCE::FFT fft;
};
