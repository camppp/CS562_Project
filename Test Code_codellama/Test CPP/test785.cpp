void simulateInterrupt(int inputSequence[], int sequenceLength) {
    int pinNumber = 0;
    int inputValue = 0;
    for (int i = 0; i < sequenceLength; i++) {
        if (inputSequence[i] == 1) {
            inputValue = 1;
        } else {
            inputValue = 0;
        }
        printf("Edge on pin %d, reading %d.\n", pinNumber, inputValue);
    }
}
