public function createSchema($backendType, $schemaDefinitions) {
    // Check if the backend type is supported
    if (!in_array($backendType, array('mysql', 'postgresql', 'sqlite'))) {
        throw new Exception("Unsupported backend type: $backendType");
    }

    // Initialize the SQL commands
    $sqlCommands = array();

    // Iterate over the schema definitions
    foreach ($schemaDefinitions as $tableName => $tableDefinition) {
        // Check if the table already exists
        if ($this->tableExists($tableName)) {
            continue;
        }

        // Create the table
        $sqlCommands[] = "CREATE TABLE $tableName (";

        // Iterate over the columns
        foreach ($tableDefinition['columns'] as $columnName => $columnDefinition) {
            // Check if the column already exists
            if ($this->columnExists($tableName, $columnName)) {
                continue;
            }

            // Create the column
            $sqlCommands