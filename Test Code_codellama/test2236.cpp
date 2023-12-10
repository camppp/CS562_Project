#include <iostream>
#include <unordered_map>

class TableManager {
private:
    std::unordered_map<int, int> tableCapacityMap;
    std::unordered_map<int, std::string> assignedTablesMap;

public:
    void createTable(int tableNumber, int capacity) {
        tableCapacityMap[tableNumber] = capacity;
    }

    void updateTableCapacity(int tableNumber, int newCapacity) {
        if (tableCapacityMap.find(tableNumber) != tableCapacityMap.end()) {
            tableCapacityMap[tableNumber] = newCapacity;
        } else {
            std::cout << "Table not found." << std::endl;
        }
    }

    void deleteTable(int tableNumber) {
        tableCapacityMap.erase(tableNumber);
        assignedTablesMap.erase(tableNumber);
    }

    void assignTable(int tableNumber, const std::string& customerName) {
        if (tableCapacityMap.find(tableNumber) != tableCapacityMap.end()) {
            assignedTablesMap[tableNumber] = customerName;
        } else {
            std::cout << "Table not found." << std::endl;
        }
    }

    void unassignTable(int tableNumber) {
        assignedTablesMap.erase(tableNumber);
    }
};
