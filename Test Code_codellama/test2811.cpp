#include <vector>
#include <string>

class StringTableDataModel {
public:
    // Adds a new row of string data to the table
    void addRow(const std::vector<std::string>& rowData) {
        rows_.push_back(rowData);
    }

    // Removes the row at the specified index
    void removeRow(int rowIndex) {
        rows_.erase(rows_.begin() + rowIndex);
    }

    // Retrieves the string data at the specified row and column index
    std::string getData(int rowIndex, int colIndex) const {
        return rows_[rowIndex][colIndex];
    }

    // Returns the total number of rows in the table
    int getRowCount() const {
        return rows_.size();
    }

    // Returns the total number of columns in the table
    int getColumnCount() const {
        if (rows_.empty()) {
            return 0;
        }
        return rows_[0].size();
    }

private:
    std::vector<std::vector<std::string>> rows_;
};
