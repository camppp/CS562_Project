#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

// Define the function type for consuming check results
using CheckResultConsumerFn = std::function<void (CheckSeverity, const LDDocument&)>;

// Enum for severity levels
enum class CheckSeverity { INFO, WARNING, ERROR };

// Sample document class
class LDDocument {
    // Define the document structure and methods
};

// ErrorChecker class for registering checks and triggering them
class ErrorChecker {
private:
    std::unordered_map<CheckSeverity, std::vector<CheckResultConsumerFn>> checkConsumers;

public:
    // Method to register a check function for a severity level
    void registerCheck(CheckSeverity severity, CheckResultConsumerFn consumerFn) {
        checkConsumers[severity].push_back(consumerFn);
    }

    // Method to trigger the registered check functions for the given document
    void checkDocument(const LDDocument& document) {
        // Assume document processing logic here
        // Trigger the registered check functions based on severity levels
        for (const auto& severityChecks : checkConsumers) {
            for (const auto& consumerFn : severityChecks.second) {
                consumerFn(severityChecks.first, document);
            }
        }
    }
};

int main() {
    // Create an instance of ErrorChecker
    ErrorChecker errorChecker;

    // Register check functions for different severity levels
    errorChecker.registerCheck(CheckSeverity::INFO, [](CheckSeverity severity, const LDDocument& document) {
        std::cout << "INFO check triggered for document" << std::endl;
        // Add specific check logic here
    });

    errorChecker.registerCheck(CheckSeverity::WARNING, [](CheckSeverity severity, const LDDocument& document) {
        std::cout << "WARNING check triggered for document" << std::endl;
        // Add specific check logic here
    });

    errorChecker.registerCheck(CheckSeverity::ERROR, [](CheckSeverity severity, const LDDocument& document) {
        std::cout << "ERROR check triggered for document" << std::endl;
        // Add specific check logic here
    });

    // Create a sample document
    LDDocument sampleDocument;

    // Trigger the checks for the sample document
    errorChecker.checkDocument(sampleDocument);

    return 0;
}
