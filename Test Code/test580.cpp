std::pair<FileSystem, SymbolTable> initializeFileSystemAndSymbolTable(FileSystem file_system, Options options) {
    SymbolTable symbol_table;
    if (options.fakeSymbolTableEnabled()) {
        symbol_table = Stats::SymbolTableCreator::initAndMakeSymbolTable(true);
    } else {
        symbol_table = Stats::SymbolTableCreator::initAndMakeSymbolTable(false);
    }
    return std::make_pair(file_system, symbol_table);
}
