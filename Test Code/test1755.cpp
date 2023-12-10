#include <iostream>
#include <chrono>
#include <map>

class PerfCounter {
private:
    static std::map<std::string, std::chrono::high_resolution_clock::time_point> startTimes;

public:
    static void initialize() {
        startTimes.clear();
    }

    static void startTiming(const std::string& sectionName) {
        startTimes[sectionName] = std::chrono::high_resolution_clock::now();
    }

    static void stopTiming(const std::string& sectionName) {
        // No-op if the section was not started
        if (startTimes.find(sectionName) != startTimes.end()) {
            auto endTime = std::chrono::high_resolution_clock::now();
            auto startTime = startTimes[sectionName];
            double elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
            std::cerr << "Elapsed time for section '" << sectionName << "': " << elapsedTime << " ms\n";
            startTimes.erase(sectionName);
        }
    }

    static double getElapsedTime(const std::string& sectionName) {
        if (startTimes.find(sectionName) != startTimes.end()) {
            auto endTime = std::chrono::high_resolution_clock::now();
            auto startTime = startTimes[sectionName];
            return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
        }
        return 0.0;  // Return 0 if section was not started or already stopped
    }

    static void printPerformanceData() {
        std::cerr << "Performance Data:\n";
        for (const auto& entry : startTimes) {
            std::cerr << "Section '" << entry.first << "': Running\n";
        }
    }
};

std::map<std::string, std::chrono::high_resolution_clock::time_point> PerfCounter::startTimes;

class VisitorPretty {
    // Implementation of VisitorPretty class is not provided as it is not directly related to the problem.
};

int main(int argc, char* argv[]) {
    // Process command-line arguments and initialize the performance counter and visitor
    // ...

    PerfCounter::initialize();
    VisitorPretty visitor;

    // Rest of the main function
    // ...
}
