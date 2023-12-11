#include <iostream>
#include <string>

void runServerGroupTests(const std::string& serverGroupName) {
    // Get the list of test suites for the specified server group
    const std::vector<std::string>& testSuites = getTestSuites(serverGroupName);

    // Iterate over the test suites and execute the tests
    for (const std::string& testSuiteName : testSuites) {
        // Get the list of tests for the current test suite
        const std::vector<std::string>& tests = getTests(testSuiteName);

        // Iterate over the tests and execute them
        for (const std::string& testName : tests) {
            // Execute the test and get the result
            const bool result = executeTest(testSuiteName, testName);

            // Print the result in the desired format
            std::cout << "Server Group: " << serverGroupName << std::endl;
            std::cout << "Test Case: " << testSuiteName << "." << testName << " - " << (result ? "Passed" : "Failed") << std::endl;
        }
    }
}
