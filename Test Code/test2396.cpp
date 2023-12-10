// TestFramework.cpp
#include "TestFramework.h"
#include <iostream>

void TestFramework::addTest(std::function<void()> testFunction) {
    testCases.push_back(testFunction);
}

void TestFramework::runTests() {
    for (const auto& test : testCases) {
        TestResult result;
        try {
            test();
            result.passed = true;
        } catch (...) {
            result.passed = false;
        }
        results.push_back(result);
    }
}

void TestFramework::printResults() {
    int passedCount = 0;
    int failedCount = 0;

    for (const auto& result : results) {
        if (result.passed) {
            std::cout << "Test passed" << std::endl;
            passedCount++;
        } else {
            std::cout << "Test failed" << std::endl;
            failedCount++;
        }
    }

    std::cout << "Total tests: " << results.size() << std::endl;
    std::cout << "Passed: " << passedCount << std::endl;
    std::cout << "Failed: " << failedCount << std::endl;
}
