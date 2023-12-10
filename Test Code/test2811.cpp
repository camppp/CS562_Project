#include <string>
#include <vector>

class StringTableDataModel {
private:
    std::vector<std::vector<std::string>> tableData;

public:
    // Adds a new row of string data to the table
    void addRow(const std::vector<std::string>& rowData) {
        tableData.push_back(rowData);
    }

    // Removes the row at the specified index
    void removeRow(int rowIndex) {
        if (rowIndex >= 0 && rowIndex < tableData.size()) {
            tableData.erase(tableData.begin() + rowIndex);
        }
    }

    // Retrieves the string data at the specified row and column index
    std::string getData(int rowIndex, int colIndex) const {
        if (rowIndex >= 0 && rowIndex < tableData.size() &&
            colIndex >= 0 && colIndex < tableData[rowIndex].size()) {
            return tableData[rowIndex][colIndex];
        }
        return "";  // Return empty string if index is out of bounds
    }

    // Returns the total number of rows in the table
    int getRowCount() const {
        return tableData.size();
    }

    // Returns the total number of columns in the table
    int getColumnCount() const {
        if (tableData.empty()) {
            return 0;
        }
        return tableData[0].size();
    }
};
