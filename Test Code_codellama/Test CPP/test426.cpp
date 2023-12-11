#include <functional>
#include <map>
#include <string>
#include <vector>

// Define the function type for the check result consumer
using CheckResultConsumerFn = std::function<void(int severity, const std::string& document)>;

// Define the class for the error checker
class ErrorChecker {
public:
    // Register a check function for a given severity level
    void registerCheck(int severity, CheckResultConsumerFn checkFunction) {
        // Add the check function to the map of check functions for the given severity level
        checkFunctions_[severity].push_back(checkFunction);
    }

    // Check a document and trigger the registered check functions for the appropriate severity levels
    void checkDocument(const std::string& document) {
        // Iterate over the check functions for each severity level
        for (auto& checkFunctions : checkFunctions_) {
            // Iterate over the check functions for the current severity level
            for (auto& checkFunction : checkFunctions.second) {
                // Trigger the check function with the document and the severity level
                checkFunction(checkFunctions.first, document);
            }
        }
    }

private:
    // Map of check functions for each severity level
    std::map<int, std::vector<CheckResultConsumerFn>> checkFunctions_;
};

// Sample usage of the ErrorChecker class
int main() {
    // Create an instance of the ErrorChecker class
    ErrorChecker errorChecker;

    // Register a check function for severity level 1
    errorChecker.registerCheck(1, [](int severity, const std::string& document) {
        // Check the document for errors
        if (document.find("error") != std::string::npos) {
            // Report the error
            std::cout << "Error found in document with severity level " << severity << std::endl;
        }
    });

    // Register a check function for severity level 2
    errorChecker.registerCheck(2, [](int severity, const std::string& document) {
        // Check the document for warnings
        if (document.find("warning") != std::string::npos) {
            // Report the warning
            std::cout << "Warning found in document with severity level " << severity << std::endl;
        }
    });

    // Check a sample document
    std::string document = "This is a sample document with an error and a warning.";
    errorChecker.checkDocument(document);

    return 0;
}
