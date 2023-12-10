#include <stdexcept>
#include <fmt/core.h>

// Custom exception class for beam overflow
class BeamOverflowException : public std::runtime_error {
public:
    // Constructor to initialize the exception message
    BeamOverflowException(int numBeams, int maxAllowed)
        : std::runtime_error(fmt::format("Too many beams (_num_beams: {:d}). Max allowed is: {:d}", numBeams, maxAllowed)) {}
};

// Class responsible for tracking and managing beams
class hsaTrackingBeamform {
public:
    // Method that may throw BeamOverflowException
    void trackBeams(int _num_beams) {
        if (_num_beams > MAX_NUM_BEAMS) {
            throw BeamOverflowException(_num_beams, MAX_NUM_BEAMS);
        }
        // Track the beams
    }

    // Destructor for hsaTrackingBeamform
    ~hsaTrackingBeamform() {
        // Clean up resources
    }
};

int main() {
    hsaTrackingBeamform tracker;
    try {
        // Simulate tracking beams with a number that may exceed the limit
        tracker.trackBeams(100);  // Assuming MAX_NUM_BEAMS is 50
    } catch (const BeamOverflowException& ex) {
        // Handle the exception, e.g., log the error and take appropriate action
        // Example: std::cerr << "Beam overflow error: " << ex.what() << std::endl;
    }
    // Continue with program execution
    return 0;
}
