class Profiler {
private:
    // Total time accumulated from all samples in milliseconds
    double totalTimeMS;

    // Number of samples
    int numSamples;

public:
    // Constructor
    Profiler() : totalTimeMS(0), numSamples(0) {}

    // Add a time sample in milliseconds
    void AddSample(double timeMS) {
        totalTimeMS += timeMS;
        numSamples++;
    }

    // Get the total time accumulated from all samples in milliseconds
    double GetTotalTimeMS() {
        return totalTimeMS;
    }

    // Get the average time in milliseconds
    double GetAverageTimeMS() {
        if (numSamples == 0) {
            return 0;
        }
        return totalTimeMS / numSamples;
    }
};
