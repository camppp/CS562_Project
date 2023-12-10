#include <iostream>

class CswClockedDevice {
private:
    int _nChannels; // Number of channels
    int pSampleRate; // Sample rate

public:
    CswClockedDevice(): _nChannels(0), pSampleRate(100) {}

    void setChannels(int channels) {
        _nChannels = channels;
    }

    int getSampleRate() {
        return pSampleRate;
    }

    void setSampleRate(int sampleRate) {
        pSampleRate = sampleRate;
    }
};

int main() {
    CswClockedDevice device;
    device.setChannels(8);
    device.setSampleRate(200);
    std::cout << "Sample rate: " << device.getSampleRate() << std::endl; // Output: Sample rate: 200
    return 0;
}
