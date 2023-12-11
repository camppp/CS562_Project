#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>

class DatabaseBulkProcessor {
public:
    DatabaseBulkProcessor(const std::string& dbFilePath) {
        // Initialize the database connection
        sqlite3_open(dbFilePath.c_str(), &db);

        // Set the journal mode to WAL
        sqlite3_exec(db, "PRAGMA journal_mode = WAL", NULL, NULL, NULL);
    }

    ~DatabaseBulkProcessor() {
        // Close the database connection
        sqlite3_close(db);
    }

    void setBulkSize(int bulkSize) {
        this->bulkSize = bulkSize;
    }

    void processData(const std::vector<std::string>& data) {
        // Check if the bulk size is set
        if (bulkSize == 0) {
            throw std::runtime_error("Bulk size not set");
        }

        // Split the data into chunks of the configured bulk size
        std::vector<std::vector<std::string>> chunks;
        for (int i = 0; i < data.size(); i += bulkSize) {
            chunks.push_back(std::vector<std::string>(data.begin() + i, data.begin() + i + bulkSize));
        }

        // Process each chunk in bulk
        for (const auto& chunk : chunks) {
            // Prepare the SQL statement
            std::string sql = "INSERT INTO mytable (name, age) VALUES ";
            for (int i = 0; i < chunk.size(); i++) {
                sql += "('" + chunk[i] + "', " + std::to_string(i) + ")";
                if (i < chunk.size() - 1) {
                    sql += ", ";
                }
            }

            // Execute the SQL statement
            sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL);
        }
    }

    void setJournalMode(const std::string& journalMode) {
        // Set the journal mode
        sqlite3_exec(db, "PRAGMA journal_mode = " + journalMode, NULL, NULL, NULL);
    }

private:
    sqlite3* db;
    int bulkSize = 0;
};
