#include <iostream>
#include <vector>
#include <cmath>

// Define the CaloRegion class
class CaloRegion {
public:
    // Member function to return hardware transverse momentum
    double hwPt() const {
        // Implementation of hwPt() function
        // Return the hardware transverse momentum
    }
};

// Define the totalPhysicalEtSum function
double totalPhysicalEtSum(const std::vector<CaloRegion>& regions, const std::vector<double>& cosPhi, double jetLsb) {
    double totalEtSum = 0.0;
    // Iterate through each CaloRegion and calculate the physical ET sum
    for (size_t i = 0; i < regions.size(); ++i) {
        // Calculate the physical ET for the current region and add it to the total sum
        totalEtSum += jetLsb * regions[i].hwPt() * cosPhi[i];
    }
    return totalEtSum;
}

int main() {
    // Example usage
    std::vector<CaloRegion> regions;  // Populate with CaloRegion objects
    std::vector<double> cosPhi;  // Populate with pre-calculated cosine values
    double jetLsb = 0.1;  // Example value for jet least significant bit

    // Calculate the total physical ET sum
    double totalEtSum = totalPhysicalEtSum(regions, cosPhi, jetLsb);
    std::cout << "Total Physical ET Sum: " << totalEtSum << std::endl;

    return 0;
}
