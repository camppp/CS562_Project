class CQuadratureCounter_TIM4 : public IQuadratureCounter_TIMX {
private:
    int position;

    // Private constructor to prevent instantiation
    CQuadratureCounter_TIM4() : position(0) {}

public:
    // Method to get the current position of the encoder
    int getCount() {
        // Implement the logic to read and return the current position from PB6 and PB7 lines
        return position; // Placeholder, replace with actual logic
    }

    // Method to reset the position to zero
    void reset() {
        position = 0;
    }

    // Method to destroy the singleton object
    static void destroyInstance(CQuadratureCounter_TIM4* instance) {
        delete instance;
    }

    // Method to get the singleton instance
    static CQuadratureCounter_TIM4* getInstance() {
        static CQuadratureCounter_TIM4 instance;
        return &instance;
    }
};
