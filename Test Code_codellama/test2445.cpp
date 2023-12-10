class DAISY {
public:
    DAISY() {}

    void begin(void (*callback)()) {
        // Store the provided callback function for later use
        this->callback = callback;

        // Simulate the start of audio processing
        // ...
    }

    void end() {
        // Stop the audio processing
        // ...

        // Reset the stored callback function
        this->callback = nullptr;
    }

private:
    void (*callback)();
};
