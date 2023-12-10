#include <cstdint>

class DataReader {
public:
    DataReader(uint8_t* data, size_t size) {
        // Constructor implementation
    }
    // Other member functions and data members
};

class DataWriter {
public:
    DataWriter(uint8_t* data, size_t size) {
        // Constructor implementation
    }
    // Other member functions and data members
};

DataWriter manipulateMemory(uint8_t* data, size_t size, DataDefinition* definition) {
    auto inPtr = reinterpret_cast<uint8_t*>(data);

    DataReader src(inPtr, size);
    DataWriter dst = allocate(&_dataBuffer, definition->getSize());

    return dst;
}
