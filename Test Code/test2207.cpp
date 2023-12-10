#include <iostream>

class DataType {
private:
    int num_bits;

public:
    DataType(int bits) : num_bits(bits) {}

    int bits() const {
        return num_bits;
    }
};

DataType determineOutputType(DataType input_dtype, DataType out_dtype) {
    if (out_dtype.bits() == 0) {
        out_dtype = input_dtype;
    }
    return out_dtype;
}

int main() {
    // Example usage
    DataType input_type(32);
    DataType desired_output_type(0);

    DataType output_type = determineOutputType(input_type, desired_output_type);
    std::cout << "Output Data Type: " << output_type.bits() << " bits" << std::endl;

    return 0;
}
