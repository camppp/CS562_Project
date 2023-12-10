#include <iostream>

class LinearKnob {
private:
    double start_frame;
    double end_frame;
    double end_val;

public:
    LinearKnob(double start_frame, double end_frame, double end_val) 
        : start_frame(start_frame), end_frame(end_frame), end_val(end_val) {}

    bool isActive(double frame) {
        return (start_frame <= frame && frame <= end_frame);
    }

    double getValue(double frame) {
        if (frame <= start_frame) {
            return 0.0;  // Knob value is 0 before the active range
        } else if (frame >= end_frame) {
            return end_val;  // Knob value is maximum after the active range
        } else {
            // Linear interpolation to calculate knob value within the active range
            return ((frame - start_frame) / (end_frame - start_frame)) * end_val;
        }
    }
};

int main() {
    // Example usage
    LinearKnob knob(10.0, 20.0, 100.0);
    std::cout << "Knob is active at frame 15: " << std::boolalpha << knob.isActive(15.0) << std::endl;
    std::cout << "Value of the knob at frame 15: " << knob.getValue(15.0) << std::endl;
    return 0;
}
