#include <chrono>

class Profiler {
private:
    std::chrono::milliseconds::rep mTotalTimeMS;
    size_t mNumSamples;

public:
    Profiler() : mTotalTimeMS(0), mNumSamples(0) {}

    void AddSample(std::chrono::milliseconds::rep sample) {
        mTotalTimeMS += sample;
        mNumSamples++;
    }

    std::chrono::milliseconds::rep GetTotalTimeMS() const {
        return mTotalTimeMS;
    }

    std::chrono::milliseconds::rep GetAverageTimeMS() const {
        return mNumSamples == 0 ? 0 : mTotalTimeMS / mNumSamples;
    }
};
