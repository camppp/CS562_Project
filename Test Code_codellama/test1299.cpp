void parseQuery(string query) {
    // Split the query into its components
    vector<string> tokens = split(query, " ");

    // Extract the table name
    string tableName = tokens[2];

    // Extract the columns
    vector<string> columns;
    for (int i = 3; i < tokens.size(); i++) {
        if (tokens[i] == "FROM") {
            break;
        }
        columns.push_back(tokens[i]);
    }

    // Extract the conditions
    vector<string> conditions;
    for (int i = tokens.size() - 1; i >= 3; i--) {
        if (tokens[i] == "WHERE") {
            break;
        }
        conditions.push_back(tokens[i]);
    }

    // Print the results
    cout << "Table: " << tableName << endl;
    cout << "Columns: " << endl;
    for (int i = 0; i < columns.size(); i++) {
        cout << columns[i] << endl;
    }
    cout << "Conditions: " << endl;
    for (int i = 0; i < conditions.size(); i++) {
        cout << conditions[i] << endl;
    }
}
