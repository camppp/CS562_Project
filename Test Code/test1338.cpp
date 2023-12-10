#include <iostream>

class AudioClip {
private:
    int mBitsPerSample;
    int mSampleRate;

public:
    // Constructor
    AudioClip(int bitsPerSample, int sampleRate) : mBitsPerSample(bitsPerSample), mSampleRate(sampleRate) {}

    // Method to return the number of bits per sample
    int bitsPerSample() const {
        return mBitsPerSample;
    }

    // Method to return the sample rate
    int sampleRate() const {
        return mSampleRate;
    }
};

int main() {
    // Create an AudioClip object with 16 bits per sample and a sample rate of 44100 Hz
    AudioClip audioClip(16, 44100);

    // Display the bits per sample and sample rate
    std::cout << "Bits per sample: " << audioClip.bitsPerSample() << std::endl;
    std::cout << "Sample rate: " << audioClip.sampleRate() << " Hz" << std::endl;

    return 0;
}
