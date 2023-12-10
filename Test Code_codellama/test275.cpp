HashTable::HashTable(int size) {
    tableSize = size;
    table = new std::string*[tableSize];
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr;
    }
}
