#include <iostream>
#include <vector>
#include <string>

// Define the SpectrumInfo class
class SpectrumInfo {
    // Define the necessary properties and methods for SpectrumInfo
};

// Define the SetPeakMetadata class
class SetPeakMetadata {
private:
    const SpectrumInfo& spectrumInfo;
    std::vector<std::string> peakMetadata;

public:
    // Constructor to initialize spectrumInfo reference
    SetPeakMetadata(const SpectrumInfo& _spectrumInfo) : spectrumInfo(_spectrumInfo) {}

    // Method to add peak metadata
    void addPeakMetadata(const std::string& metadata) {
        peakMetadata.push_back(metadata);
    }

    // Method to retrieve peak metadata for a given peak index
    std::string getPeakMetadata(int peakIndex) {
        if (peakIndex >= 0 && peakIndex < peakMetadata.size()) {
            return peakMetadata[peakIndex];
        }
        return "Invalid peak index";
    }

    // Method to update peak metadata for a given peak index
    void updatePeakMetadata(int peakIndex, const std::string& newMetadata) {
        if (peakIndex >= 0 && peakIndex < peakMetadata.size()) {
            peakMetadata[peakIndex] = newMetadata;
        }
    }

    // Method to remove peak metadata for a given peak index
    void removePeakMetadata(int peakIndex) {
        if (peakIndex >= 0 && peakIndex < peakMetadata.size()) {
            peakMetadata.erase(peakMetadata.begin() + peakIndex);
        }
    }
};

int main() {
    // Example usage
    SpectrumInfo spectrum;  // Initialize SpectrumInfo object
    SetPeakMetadata peakMetadata(spectrum);  // Initialize SetPeakMetadata object

    peakMetadata.addPeakMetadata("Peak 1: Metadata 1");
    peakMetadata.addPeakMetadata("Peak 2: Metadata 2");

    std::cout << peakMetadata.getPeakMetadata(0) << std::endl;  // Output: Peak 1: Metadata 1

    peakMetadata.updatePeakMetadata(1, "Updated Metadata 2");
    std::cout << peakMetadata.getPeakMetadata(1) << std::endl;  // Output: Updated Metadata 2

    peakMetadata.removePeakMetadata(0);
    std::cout << peakMetadata.getPeakMetadata(0) << std::endl;  // Output: Invalid peak index

    return 0;
}
