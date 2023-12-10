#include <sqlite3.h>
#include <string>

std::string openDatabase(const std::string& s_dbPath) {
    sqlite3* db;
    int rc = sqlite3_open(s_dbPath.c_str(), &db);
    if (rc != SQLITE_OK) {
        return "Failed to open database: " + std::string(sqlite3_errmsg(db));
    }
    return "Successfully opened database";
}
