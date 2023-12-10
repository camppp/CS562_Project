#include <iostream>
#include <vector>
#include <string>

// Function to calculate the MZs of y ion fragments
void calculateYIonMZs(std::string peptideSequence, std::vector<double>& vvdYionMass) {
    // Define the mass values of amino acids
    std::unordered_map<char, double> aminoAcidMass = {
        {'A', 71.03711},
        {'R', 156.10111},
        {'N', 114.04293},
        {'D', 115.02694},
        {'C', 103.00919},
        {'E', 129.04259},
        {'Q', 128.05858},
        {'G', 57.02146},
        {'H', 137.05891},
        {'I', 113.08406},
        {'L', 113.08406},
        {'K', 128.09496},
        {'M', 131.04049},
        {'F', 147.06841},
        {'P', 97.05276},
        {'S', 87.03203},
        {'T', 101.04768},
        {'W', 186.07931},
        {'Y', 163.06333},
        {'V', 99.06841}
    };

    // Calculate the MZs of y ion fragments
    double yIonMass = 0;
    for (int i = 1; i < peptideSequence.length(); i++) {
        yIonMass += aminoAcidMass[peptideSequence[i - 1]];
        vvdYionMass[i - 1] = (yIonMass + 1) / 1; // Assuming charge = 1
    }
}

int main() {
    std::string peptideSeq = "PEPTIDE";
    std::vector<double> yIonMasses(peptideSeq.length() - 1, 0);
    calculateYIonMZs(peptideSeq, yIonMasses);

    // Output the calculated MZs of y ion fragments
    for (double mz : yIonMasses) {
        std::cout << mz << " ";
    }
    return 0;
}
