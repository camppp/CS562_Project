std::vector<uint32_t> transformAndSort(const uint32_t* u32Data, size_t sizeInU32) {
    // Create a new vector to store the transformed and sorted data
    std::vector<uint32_t> transformedData(sizeInU32);

    // Iterate over the input data and perform the transformation
    for (size_t i = 0; i < sizeInU32; i++) {
        // Double the value of each element in the input array
        transformedData[i] = u32Data[i] * 2;
    }

    // Sort the transformed data in non-decreasing order
    std::sort(transformedData.begin(), transformedData.end());

    return transformedData;
}
