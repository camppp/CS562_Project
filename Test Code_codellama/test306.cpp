#include <iostream>
#include <vector>
#include <string>

class TestRegistry {
public:
    void addTest(const std::string& testName) {
        tests.push_back(testName);
    }

    void runAllTests() {
        for (const auto& test : tests) {
            std::cout << "Running test: " << test << std::endl;
            // Run the test and store the result
            bool passed = runTest(test);
            results.push_back(passed);
        }
    }

    std::vector<bool> getTestResults() {
        return results;
    }

private:
    std::vector<std::string> tests;
    std::vector<bool> results;

    bool runTest(const std::string& testName) {
        // Implement the logic to run the test and return the result
        return true;
    }
};
