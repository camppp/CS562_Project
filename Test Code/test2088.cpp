#include <iostream>

enum class DataType {
    INT32,
    FLOAT32,
    // Add other data types as needed
};

struct BufferDesc {
    DataType element_type;
    // Other buffer information
};

void processBuffer(BufferDesc* buffer_desc) {
    if (buffer_desc->element_type == DataType::INT32) {
        // Perform integer-specific operations
        std::cout << "Performing operations for INT32 buffer" << std::endl;
    } else if (buffer_desc->element_type == DataType::FLOAT32) {
        // Perform float-specific operations
        std::cout << "Performing operations for FLOAT32 buffer" << std::endl;
    }
}

int main() {
    BufferDesc int_buffer {DataType::INT32};
    BufferDesc float_buffer {DataType::FLOAT32};

    processBuffer(&int_buffer);  // Output: Performing operations for INT32 buffer
    processBuffer(&float_buffer);  // Output: Performing operations for FLOAT32 buffer

    return 0;
}
