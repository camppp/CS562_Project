#include <string>
#include <vector>

class SEBurnWound {
private:
    std::vector<std::string> m_compartmentsAffected;

public:
    SEBurnWound() {}

    void SetCompartment(const std::string& name) {
        m_compartmentsAffected.push_back(name);
    }

    std::vector<std::string> GetAffectedCompartments() {
        return m_compartmentsAffected;
    }
};
