#include <iostream>

enum AddressMode { Page, Vertical };

class DisplayController {
private:
    int startLine;
    AddressMode addressingMode;
    int contrast;
    bool segmentRemap;
    bool comScanDirection;
    int muxRatio;

public:
    void setDisplayStartLine(int line) {
        startLine = line;
    }

    void setAddressingMode(AddressMode mode) {
        addressingMode = mode;
    }

    void setContrast(int value) {
        contrast = value;
    }

    void setSegmentRemap(bool remap) {
        segmentRemap = remap;
    }

    void setComScanDirection(bool direction) {
        comScanDirection = direction;
    }

    void setMuxRatio(int ratio) {
        muxRatio = ratio;
    }

    int calculateTotalPixels() {
        if (addressingMode == Page) {
            int totalPages = 64 / muxRatio; // Assuming 64 is the total number of lines
            return 128 * muxRatio * totalPages;
        } else {
            return 128 * muxRatio;
        }
    }
};

int main() {
    DisplayController display;
    display.setDisplayStartLine(0);
    display.setAddressingMode(Page);
    display.setContrast(210);
    display.setSegmentRemap(false);
    display.setComScanDirection(false);
    display.setMuxRatio(63);

    std::cout << "Total pixels: " << display.calculateTotalPixels() << std::endl;

    return 0;
}
