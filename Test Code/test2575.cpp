#include <iostream>
#include <fstream>
#include <memory>
#include "storage_manager.h"  // Assuming the necessary header file for storage manager

std::pair<std::string, std::shared_ptr<hyrise::storage::AbstractTable>> loadQueryAndReference(const std::string& numberString) {
    std::string query;
    std::shared_ptr<hyrise::storage::AbstractTable> refTable;

    // Load table file using storage manager
    auto* sm = io::StorageManager::getInstance();
    sm->loadTableFile("refTable", "tpcch/query" + numberString + "_result.tbl");

    // Load query from file
    std::ifstream file("test/tpcch/query" + numberString + ".json");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            query += line;
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to open query file." << std::endl;
    }

    // Retrieve reference table from storage manager
    refTable = sm->getTable("refTable");

    return std::make_pair(query, refTable);
}
