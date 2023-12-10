class DisplayController {
public:
    // ...

    int calculateTotalPixels() {
        int totalPixels = 0;

        if (addressingMode == "Page") {
            totalPixels = 128 * muxRatio * numberOfPages;
        } else if (addressingMode == "Vertical") {
            totalPixels = 128 * muxRatio;
        }

        return totalPixels;
    }

private:
    // ...

    string addressingMode;
    int muxRatio;
    int numberOfPages;
};
