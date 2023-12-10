#include <OpenMS/KERNEL/MSChromatogram.h>
#include <vector>

// Function to calculate the Total Ion Current (TIC) of an MS chromatogram
double calculateTIC(const OpenMS::MSChromatogram& chromatogram) {
    double totalIonCurrent = 0.0;
    std::vector<std::vector<double>> floatDataArrays = chromatogram.getFloatDataArrays();

    for (const auto& dataArray : floatDataArrays) {
        for (double intensity : dataArray) {
            totalIonCurrent += intensity;
        }
    }

    return totalIonCurrent;
}
