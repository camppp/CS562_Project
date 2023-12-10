#include <iostream>

enum class BTSpecialChild {
    NotInitialized
};

bool VerifyExecution(int lastResult) {
    // Implementation of VerifyExecution function
    // Return true if the last execution is valid, false otherwise
    return (lastResult >= 0);  // Example implementation, replace with actual logic
}

int GetChildrenNum() {
    // Implementation of GetChildrenNum function
    // Return the total number of children to be processed
    return 5;  // Example implementation, replace with actual logic
}

int DetermineNextChildIndex(int prevChild, int lastResult) {
    int nextChildIdx = -1;  // Initialize with an invalid value

    if (prevChild == static_cast<int>(BTSpecialChild::NotInitialized)) {
        nextChildIdx = 0;
    } else if (VerifyExecution(lastResult) && (prevChild + 1) < GetChildrenNum()) {
        nextChildIdx = prevChild + 1;
    }

    return nextChildIdx;
}

int main() {
    // Example usage
    int prevChildIndex = 2;  // Example previous child index
    int lastExecutionResult = 1;  // Example last execution result

    int nextChildIndex = DetermineNextChildIndex(prevChildIndex, lastExecutionResult);
    if (nextChildIndex != -1) {
        std::cout << "Next child index to be processed: " << nextChildIndex << std::endl;
    } else {
        std::cout << "No valid next child index found based on the given conditions." << std::endl;
    }

    return 0;
}
