#include <iostream>
#include <string>
#include <stdexcept>

enum class FixedGridEnergyDensity { Central, Forward, All };

double parseEtaRegion(const std::string& etaRegion) {
    FixedGridEnergyDensity myEtaRegion;

    if (etaRegion == "Central") {
        myEtaRegion = FixedGridEnergyDensity::Central;
    } else if (etaRegion == "Forward") {
        myEtaRegion = FixedGridEnergyDensity::Forward;
    } else if (etaRegion == "All") {
        myEtaRegion = FixedGridEnergyDensity::All;
    } else {
        std::cerr << "Wrong EtaRegion parameter: " << etaRegion << ". Using EtaRegion = Central" << std::endl;
        myEtaRegion = FixedGridEnergyDensity::Central;
    }

    return static_cast<double>(myEtaRegion);
}

int main() {
    std::string inputEtaRegion = "Forward";
    double result = parseEtaRegion(inputEtaRegion);
    std::cout << "Parsed EtaRegion value: " << result << std::endl;

    inputEtaRegion = "Unknown";
    result = parseEtaRegion(inputEtaRegion);
    std::cout << "Parsed EtaRegion value: " << result << std::endl;

    return 0;
}
