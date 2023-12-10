#include <iostream>

class LinearSegmentParameter {
private:
    unsigned short _segmentLength;
    unsigned short _segmentWidth;

public:
    // Constructor to initialize segment length and width
    LinearSegmentParameter(unsigned short length, unsigned short width) {
        _segmentLength = length;
        _segmentWidth = width;
    }

    // Getter method for segment length
    unsigned short getSegmentLength() const {
        return _segmentLength;
    }

    // Setter method for segment length
    void setSegmentLength(unsigned short length) {
        _segmentLength = length;
    }

    // Getter method for segment width
    unsigned short getSegmentWidth() const {
        return _segmentWidth;
    }

    // Setter method for segment width
    void setSegmentWidth(unsigned short width) {
        _segmentWidth = width;
    }
};

int main() {
    // Example usage
    LinearSegmentParameter segment(10, 5);
    std::cout << "Segment Length: " << segment.getSegmentLength() << std::endl;
    std::cout << "Segment Width: " << segment.getSegmentWidth() << std::endl;

    segment.setSegmentLength(15);
    segment.setSegmentWidth(8);

    std::cout << "Updated Segment Length: " << segment.getSegmentLength() << std::endl;
    std::cout << "Updated Segment Width: " << segment.getSegmentWidth() << std::endl;

    return 0;
}
