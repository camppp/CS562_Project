#include <iostream>
#include <vector>
#include <string>

class TestRunner {
private:
    struct TestCase {
        std::string name;
        void (*function)();
        bool passed;

        TestCase(const std::string& n, void (*f)()) : name(n), function(f), passed(false) {}
    };

    std::vector<TestCase> testCases;

public:
    void registerTest(const std::string& testName, void (*testFunction)()) {
        testCases.emplace_back(testName, testFunction);
    }

    void runTests() {
        int passedCount = 0;
        for (const auto& testCase : testCases) {
            try {
                testCase.function();
                std::cout << "Test case '" << testCase.name << "' passed" << std::endl;
                testCase.passed = true;
                passedCount++;
            } catch (...) {
                std::cout << "Test case '" << testCase.name << "' failed" << std::endl;
            }
        }
        std::cout << "Summary: " << passedCount << " out of " << testCases.size() << " test cases passed" << std::endl;
    }
};

// Example usage
void testAddition() {
    int result = 2 + 2;
    if (result == 4) {
        // Test passed
    } else {
        throw std::runtime_error("Addition test failed");
    }
}

void testSubtraction() {
    int result = 5 - 3;
    if (result == 2) {
        // Test passed
    } else {
        throw std::runtime_error("Subtraction test failed");
    }
}

int main() {
    TestRunner testRunner;
    testRunner.registerTest("Addition", testAddition);
    testRunner.registerTest("Subtraction", testSubtraction);
    testRunner.runTests();
    return 0;
}
