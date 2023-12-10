#include <string>
#include <vector>
#include <sqlite3.h>

enum class Index { No, Yes, Unique } _seq_index = Index::Unique;
enum class Journal { Default, Wal } _journal = Journal::Wal;

class DatabaseBulkProcessor {
private:
    sqlite3* _db;
    size_t _bulk_size = 0;
    size_t _bulk_counter = 0;

public:
    DatabaseBulkProcessor(const std::string& dbFilePath) {
        int rc = sqlite3_open(dbFilePath.c_str(), &_db);
        if (rc) {
            throw std::runtime_error("Failed to open database: " + std::string(sqlite3_errmsg(_db)));
        }
    }

    void setBulkSize(size_t bulkSize) {
        _bulk_size = bulkSize;
    }

    void setJournalMode(Journal journalMode) {
        std::string mode = (journalMode == Journal::Default) ? "DELETE" : "WAL";
        std::string query = "PRAGMA journal_mode = " + mode;
        int rc = sqlite3_exec(_db, query.c_str(), nullptr, nullptr, nullptr);
        if (rc != SQLITE_OK) {
            throw std::runtime_error("Failed to set journal mode");
        }
    }

    void processData(const std::vector<std::string>& data) {
        for (const auto& item : data) {
            // Process the data item
            // ...

            // Check if bulk size is reached
            if (++_bulk_counter >= _bulk_size) {
                // Perform bulk processing
                // ...

                // Reset bulk counter
                _bulk_counter = 0;
            }
        }
    }

    ~DatabaseBulkProcessor() {
        if (_db) {
            sqlite3_close(_db);
        }
    }
};
