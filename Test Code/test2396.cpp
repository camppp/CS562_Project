#include "TestFramework.h"

void TestFramework::addTest(std::function<void()> testFunction) {
    testCases.push_back(testFunction);
}

void TestFramework::runTests() {
    for (auto& testCase : testCases) {
        try {
            testCase();
            results.push_back({testCase.name(), true});
        } catch (const std::exception& e) {
            results.push_back({testCase.name(), false});
        }
    }
}

void TestFramework::printResults() {
    std::cout << "Test Results:" << std::endl;
    for (auto& result : results) {
        std::cout << result.testName << ": " << (result.passed ? "Passed" : "Failed") << std::endl;
    }
}
