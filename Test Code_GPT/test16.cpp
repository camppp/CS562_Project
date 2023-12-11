#include <iostream>
#include <vector>

class Columns {
public:
    // Method to access the singleton instance
    static Columns& getInstance() {
        // Implement the singleton pattern to ensure only one instance is created
        static Columns instance;
        return instance;
    }

    // Add any necessary methods for the Columns class here
    void addColumn(const std::string& columnName) {
        columns.push_back(columnName);
    }

    void displayColumns() const {
        std::cout << "Columns in the database table:" << std::endl;
        for (const auto& column : columns) {
            std::cout << "- " << column << std::endl;
        }
    }

private:
    // Private constructor to prevent instantiation
    Columns() {
        // Initialize the columns here
        columns = {"Column1", "Column2", "Column3"};
    }

    // Private destructor to prevent deletion
    ~Columns() {
        // Cleanup code here
    }

    // Private copy constructor and assignment operator to prevent copying
    Columns(const Columns&) = delete;
    Columns& operator=(const Columns&) = delete;

    // Add any necessary private attributes for the Columns class here
    std::vector<std::string> columns;
};

int main() {
    // Access the singleton instance of Columns
    Columns& columns = Columns::getInstance();

    // Perform operations using the columns instance
    columns.displayColumns();

    // You can add or modify columns using the instance
    columns.addColumn("NewColumn");

    // Display columns again
    columns.displayColumns();

    return 0;
}
