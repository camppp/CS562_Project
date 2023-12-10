#include <iostream>
#include <fstream>
#include <string>

#ifdef PROFILE
#define PROFILE_FUNC(func) func
#else
#define PROFILE_FUNC(func)
#endif

class Profiler {
public:
    Profiler() {}

    void start() {
        // Start the profiling process
        PROFILE_FUNC(tracker.Run());
    }

    void stop() {
        // Stop the profiling process
        PROFILE_FUNC(tracker.Stop());
    }

    void setFilePath(const std::string& filePath) {
        // Set the file path for the profiling data dump
        this->filePath = filePath;
    }

    void dumpData() {
        // Dump the profiling data to the file specified by the file path
        if (this->filePath.empty()) {
            // If the file path is not set, do not dump the data
            return;
        }

        std::ofstream outFile(this->filePath, std::ios::out);
        if (!outFile) {
            // If the file cannot be opened, do not dump the data
            return;
        }

        outFile << tracker.GetData();
        outFile.close();
    }

private:
    std::string filePath;
};

int main() {
    // Create a Profiler object
    Profiler profiler;

    // Set the file path for the profiling data dump
    profiler.setFilePath("trackerProfile");

    // Start the profiling process
    profiler.start();

    // Do some work
    // ...

    // Stop the profiling process
    profiler.stop();

    // Dump the profiling data to the file
    profiler.dumpData();

    return 0;
}
