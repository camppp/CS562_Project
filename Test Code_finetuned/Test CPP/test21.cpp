#include <iostream>
#include <vector>

// Define the Columns class representing columns in a database table
class Columns {
public:
    // Method to access the singleton instance
    static Columns& getInstance() {
        // Implement the singleton pattern to ensure only one instance is created
        static Columns instance;
        return instance;
    }

    // Add any necessary methods or attributes for the Columns class here
    void addColumn(const std::string& columnName) {
        columns.push_back(columnName);
    }

    void printColumns() {
        for(const auto& column : columns) {
            std::cout << column << std::endl;
        }
    }

private:
    // Private constructor to prevent instantiation
    Columns() {
        // Initialize the columns here
    }

    // Private destructor to prevent deletion
    ~Columns() {
        // Cleanup code here
    }

    // Add any necessary private attributes for the Columns class here
    std::vector<std::string> columns;
};

int main() {
    // Access the singleton instance of Columns
    Columns& columns = Columns::getInstance();

    // Add some columns
    columns.addColumn("Column1");
    columns.addColumn("Column2");
    columns.addColumn("Column3");

    // Print the columns
    columns.printColumns();

    return 0;
}