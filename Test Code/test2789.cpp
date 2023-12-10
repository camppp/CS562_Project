#include <sqlite3.h>
#include <string>

std::string openDatabase(const std::string& s_dbPath) {
    sqlite3* d_database_p;
    int openResult = sqlite3_open(s_dbPath.c_str(), &d_database_p);
    if (openResult == SQLITE_OK) {
        sqlite3_close(d_database_p);
        return "Database connection opened successfully.";
    } else {
        return "Failed to open database: " + std::string(sqlite3_errmsg(d_database_p));
    }
}
