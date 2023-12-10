#include <iostream>
#include <string>
#include <map>

// Function to calculate the molecular weight of a compound
double MolecularWeight(std::istream& is) {
  // Map to store atomic weights of elements
  std::map<std::string, double> atomicWeights = {
    {"H", 1.008}, {"C", 12.011}, {"O", 15.999}, {"N", 14.007}
    // Add more elements and their atomic weights as needed
  };

  double totalWeight = 0.0;
  char element;
  int count;

  // Read the chemical formula from the input stream
  while (is >> element >> count) {
    std::string elementStr(1, element);
    if (atomicWeights.find(elementStr) != atomicWeights.end()) {
      totalWeight += atomicWeights[elementStr] * count;
    } else {
      std::cerr << "Error: Unknown element " << elementStr << std::endl;
      return -1.0;  // Error code for unknown element
    }
  }

  return totalWeight;
}

int main() {
  // Example usage
  std::string chemicalFormula = "H2O";
  std::istringstream iss(chemicalFormula);
  double weight = MolecularWeight(iss);
  std::cout << "Molecular weight of " << chemicalFormula << " is " << weight << std::endl;

  return 0;
}
