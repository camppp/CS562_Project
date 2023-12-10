#include <iostream>
#include <map>
#include <string>

class ChemicalGroup {
private:
    double bindEnergy_;

public:
    ChemicalGroup(double bindEnergy) : bindEnergy_(bindEnergy) {}

    double bindEnergy() const {
        return bindEnergy_;
    }
};

class ChemicalBasis {
private:
    std::map<std::string, ChemicalGroup> chemicalGroups_;

public:
    void addChemicalGroup(const std::string& groupName, double bindEnergy) {
        chemicalGroups_[groupName] = ChemicalGroup(bindEnergy);
    }

    const std::map<std::string, ChemicalGroup>& chemicalGroups() const {
        return chemicalGroups_;
    }
};

int main() {
    ChemicalBasis myChemicalBasis;
    myChemicalBasis.addChemicalGroup("E", 10.5);  // Adding bind energy for chemical group "E"
    myChemicalBasis.addChemicalGroup("-NH2", 8.2);  // Adding bind energy for chemical group "-NH2"

    std::cout << "The bind energy of E is "
        << myChemicalBasis.chemicalGroups()["E"].bindEnergy()
        << std::endl;
    std::cout << "The bind energy of -NH2 is "
        << myChemicalBasis.chemicalGroups()["-NH2"].bindEnergy()
        << std::endl;

    return 0;
}
