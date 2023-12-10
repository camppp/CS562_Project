template <typename MAP_TYPE>
class SerializableMapBT {
public:
  // Other member functions and data members are not shown for brevity.

  size_t getSizeOfRunTable() const {
    // Construct the SQL query string to select all records from the run table using the runDataFunction stored procedure.
    std::string l_sqlQuerry = "CALL runDataFunction()";

    // Use the m_dbHandlerInstance to execute the query and store the results in l_runDbResults.
    pqxx::result l_runDbResults = m_dbHandlerInstance.exec(l_sqlQuerry);

    // Return the size of the result set, which represents the size of the run table.
    return l_runDbResults.size();
  }

private:
  // Other private data members and member functions are not shown for brevity.
  DBHandler m_dbHandlerInstance;  // Instance of a database handler for executing queries.
};
