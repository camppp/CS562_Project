#include <iostream>
#include <map>
#include <string>

// ChemicalGroup class
class ChemicalGroup {
public:
    ChemicalGroup(std::string name, double bindEnergy) : name_(name), bindEnergy_(bindEnergy) {}

    std::string name() const { return name_; }
    double bindEnergy() const { return bindEnergy_; }

private:
    std::string name_;
    double bindEnergy_;
};

// ChemicalBasis class
class ChemicalBasis {
public:
    ChemicalBasis() : chemicalGroups_() {}

    void addChemicalGroup(std::string name, double bindEnergy) {
        chemicalGroups_[name] = ChemicalGroup(name, bindEnergy);
    }

    ChemicalGroup& chemicalGroups() { return chemicalGroups_; }

private:
    std::map<std::string, ChemicalGroup> chemicalGroups_;
};

int main() {
    // Create a ChemicalBasis object
    ChemicalBasis myChemicalBasis;

    // Add chemical groups to the basis
    myChemicalBasis.addChemicalGroup("E", 1.0);
    myChemicalBasis.addChemicalGroup("-NH2", 2.0);

    // Retrieve the bind energy of the chemical groups
    std::cout << "The bind energy of E is "
        << myChemicalBasis.chemicalGroups()["E"].bindEnergy()
        << std::endl;
    std::cout << "The bind energy of -NH2 is "
        << myChemicalBasis.chemicalGroups()["-NH2"].bindEnergy()
        << std::endl;

    return 0;
}
