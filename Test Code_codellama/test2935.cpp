#include <sqlite3.h>
#include <cassert>

void processData(sqlite3* db) {
    int tmp_int = 0;
    int temp_int = 0;

    // Execute a SELECT query to retrieve all rows from the test3 table
    sqlite3_stmt* stmt = sqlite3_prepare_v2(db, "SELECT * FROM test3", -1, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // Retrieve the values from the current row
        int value = sqlite3_column_int(stmt, 0);
        int dec = sqlite3_column_int(stmt, 1);

        // Check the conditions for each row
        if (value == 2) {
            tmp_int = value;
        }
        if (dec == 28) {
            temp_int = dec;
        }
    }

    // Assert that tmp_int is equal to 2 and temp_int is equal to 28
    assert(tmp_int == 2);
    assert(temp_int == 28);

    // Clean up the statement
    sqlite3_finalize(stmt);
}
