size_t getSizeOfRunTable() const {
  try {
    std::string l_sqlQuery = "SELECT * FROM runDataFunction();";
    pqxx::result l_runDbResults = m_dbHandlerInstance.query(l_sqlQuery);

    return l_runDbResults.size();
  } catch (const std::exception &e) {
    // Handle any potential exceptions that may occur during the database interaction.
    // For example, log the error and return an appropriate error code or rethrow the exception.
    // Replace the following line with your error handling code.
    std::cerr << "Error occurred while retrieving the size of the run table: " << e.what() << std::endl;
    return 0;  // Return 0 to indicate an error occurred.
  }
}
