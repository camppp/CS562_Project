#include <iostream>

void decompressFile(std::istream& _decompress, std::ostream& _dest) {
    char ch = _decompress.get();  // Read the first character from the input stream

    while (!_decompress.eof() && !_decompress.fail()) {
        _dest.put(ch);  // Write the character to the output stream
        ch = _decompress.get();  // Read the next character from the input stream
    }
}
