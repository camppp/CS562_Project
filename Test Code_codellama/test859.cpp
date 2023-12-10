#include <iostream>
#include <vector>
#include <string>

class TestRunner {
public:
    void registerTest(const std::string& testName, void (*testFunction)()) {
        tests.push_back(std::make_pair(testName, testFunction));
    }

    void runTests() {
        for (const auto& test : tests) {
            test.second();
            std::cout << "Test " << test.first << " " << (test.second() ? "passed" : "failed") << std::endl;
        }
    }

private:
    std::vector<std::pair<std::string, void (*)()>> tests;
};

int main() {
    TestRunner testRunner;

    // Register test cases
    testRunner.registerTest("Test 1", []() {
        // Test 1 implementation
    });
    testRunner.registerTest("Test 2", []() {
        // Test 2 implementation
    });

    // Run test cases
    testRunner.runTests();

    return 0;
}
