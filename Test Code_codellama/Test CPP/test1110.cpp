class ErrorTester {
private:
    bool errorOccurred;

public:
    ErrorTester() : errorOccurred(false) {}

    bool GetError() {
        if (errorOccurred) {
            errorOccurred = false;
            return true;
        }
        return false;
    }

    void SetError() {
        errorOccurred = true;
    }
};
