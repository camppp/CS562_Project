#include <iostream>
#include <vector>
#include <string>

class SEBurnWound {
private:
    std::vector<std::string> m_compartmentsAffected;

public:
    void SetCompartment(const std::string& name) {
        m_compartmentsAffected.push_back(name);
    }

    std::vector<std::string> GetAffectedCompartments() const {
        return m_compartmentsAffected;
    }
};

int main() {
    SEBurnWound burnWound;
    burnWound.SetCompartment("Compartment1");
    burnWound.SetCompartment("Compartment2");
    burnWound.SetCompartment("Compartment3");

    std::vector<std::string> affectedCompartments = burnWound.GetAffectedCompartments();
    std::cout << "Affected Compartments:" << std::endl;
    for (const auto& compartment : affectedCompartments) {
        std::cout << compartment << std::endl;
    }

    return 0;
}
