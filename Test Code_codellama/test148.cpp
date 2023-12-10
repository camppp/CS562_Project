#include <wx/string.h>

class SingleStatement {
public:
    // Constructor to initialize SingleStatement with the provided SQL statement
    SingleStatement(const wxString& sql) {
        // Initialize the SingleStatement object with the provided SQL statement
        sqlStatement = sql;
    }

    // Member variable to store the SQL statement
    wxString sqlStatement;
};
