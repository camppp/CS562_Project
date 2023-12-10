#include <iostream>

void interrupt_cb(int pin, int val) {
    std::cout << "Edge on pin " << pin << ", reading " << val << "." << std::endl;
}

void simulateInterrupt(int inputSequence[], int sequenceLength) {
    int previousValue = inputSequence[0];
    for (int i = 1; i < sequenceLength; i++) {
        if (inputSequence[i] != previousValue) {
            interrupt_cb(MAIN_pin, inputSequence[i]);
            previousValue = inputSequence[i];
        }
    }
}

int main() {
    // Example usage
    int inputSequence[] = {0, 1, 1, 0, 0, 1, 1, 1, 0};
    int sequenceLength = sizeof(inputSequence) / sizeof(inputSequence[0]);
    simulateInterrupt(inputSequence, sequenceLength);
    return 0;
}
