#include <sqlite3.h>
#include <iostream>
#include <cassert>

void processData(sqlite3* db) {
    int tmp_int = 0, temp_int = 0;
    char* errMsg = nullptr;
    
    // Execute SELECT query to retrieve data from the test3 table
    const char* query = "SELECT Value, dec, str, raw FROM test3;";
    sqlite3_stmt* statement;
    int rc = sqlite3_prepare_v2(db, query, -1, &statement, nullptr);
    
    if (rc == SQLITE_OK) {
        // Iterate through the result set
        while (sqlite3_step(statement) == SQLITE_ROW) {
            int value = sqlite3_column_int(statement, 0);
            int dec = sqlite3_column_int(statement, 1);
            
            // Process the retrieved values based on conditions
            if (value == 2) {
                tmp_int = value;
            }
            if (dec == 28) {
                temp_int = dec;
            }
        }
        
        // Assert the conditions after processing all rows
        assert(tmp_int == 2);
        assert(temp_int == 28);
        
        sqlite3_finalize(statement);  // Finalize the prepared statement
    } else {
        std::cerr << "Error executing SELECT query: " << sqlite3_errmsg(db) << std::endl;
    }
}
