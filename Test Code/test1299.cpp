#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void parseQuery(const std::string& query) {
    std::string columns, table, conditions;
    std::istringstream iss(query);
    std::string select, from, where;
    iss >> select >> columns >> from >> table >> where >> conditions;

    // Remove trailing comma from columns if present
    if (columns.back() == ',') {
        columns.pop_back();
    }

    // Print the extracted information
    std::cout << "Table: " << table << std::endl;
    std::cout << "Columns:" << std::endl;
    std::istringstream columnsStream(columns);
    std::string column;
    while (std::getline(columnsStream, column, ',')) {
        std::cout << column << std::endl;
    }
    std::cout << "Conditions: " << conditions << std::endl;
}

int main() {
    std::string query = "SELECT doctor_id FROM visits WHERE LENGTH(patient_name) > 11";
    parseQuery(query);
    return 0;
}
