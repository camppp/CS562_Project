std::pair<FileSystem, SymbolTable> initializeFileSystemAndSymbolTable(FileSystem file_system, Options options) {
    // Create a symbol table based on the options
    SymbolTable symbol_table;
    if (options.fakeSymbolTableEnabled()) {
        symbol_table = SymbolTableCreator::initAndMakeSymbolTable(file_system);
    } else {
        symbol_table = SymbolTableCreator::initAndMakeSymbolTable(file_system, options.getSymbolTableOptions());
    }

    // Initialize the file system
    file_system.init(symbol_table);

    // Return the initialized file system and symbol table
    return std::make_pair(file_system, symbol_table);
}
