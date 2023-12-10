#include <iostream>

// Define the When class with the missing functionalities
class When {
private:
    std::vector<CassConsistency> consistencies_;
    std::string query_;

public:
    When() {}

    // Method to set the consistency level for the query
    void setConsistency(CassConsistency consistency) {
        consistencies_.push_back(consistency);
    }

    // Method to set the query string for the "When" section
    void setQuery(const std::string& query) {
        query_ = query;
    }

    // Method to retrieve the constructed "When" section as a string
    std::string getWhenSection() {
        std::string whenSection = "WHEN ";
        for (const auto& consistency : consistencies_) {
            whenSection += "CONSISTENCY " + std::to_string(static_cast<int>(consistency)) + " AND ";
        }
        whenSection += "QUERY " + query_;
        return whenSection;
    }
};

int main() {
    // Create an instance of the When class
    When when;

    // Set the consistency level for the query
    when.setConsistency(CassConsistency::LOCAL_ONE);
    when.setConsistency(CassConsistency::QUORUM);

    // Set the query string for the "When" section
    when.setQuery("SELECT * FROM table WHERE condition");

    // Retrieve and print the constructed "When" section
    std::cout << when.getWhenSection() << std::endl;

    return 0;
}
