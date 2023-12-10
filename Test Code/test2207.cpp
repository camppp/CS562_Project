DataType determineOutputType(DataType input_dtype, DataType out_dtype) {
    // If the desired output data type has 0 bits, set it to the number of bits in the input data type
    if (out_dtype.bits() == 0) {
        out_dtype = input_dtype;
    }
    return out_dtype;
}
