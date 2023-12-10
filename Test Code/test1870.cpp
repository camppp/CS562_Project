#include <vector>
#include <string>

enum class CassConsistency {
    LOCAL_ONE,
    LOCAL_QUORUM,
    ONE,
    QUORUM,
    SERIAL,
    LOCAL_SERIAL
};

class When {
private:
    std::vector<CassConsistency> consistencies_;
    std::string query_;

public:
    When() {}

    // Add method to set the consistency level for the query
    void setConsistency(CassConsistency consistency) {
        consistencies_.push_back(consistency);
    }

    // Add method to set the query string for the "When" section
    void setQuery(const std::string& query) {
        query_ = query;
    }

    // Add method to retrieve the constructed "When" section as a string
    std::string getWhenSection() {
        std::string whenSection = "WHEN ";
        for (const auto& consistency : consistencies_) {
            whenSection += "CONSISTENCY " + std::to_string(static_cast<int>(consistency)) + " AND ";
        }
        whenSection += "QUERY " + query_;
        return whenSection;
    }
};
