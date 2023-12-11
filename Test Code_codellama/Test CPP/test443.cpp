std::variant<std::string, int> processMatrix(const Matrix& mat) {
    // Obtain the pointer to the matrix buffer
    auto ptr = mat.getRowBuf(0);

    // Check if the matrix is valid
    if (ptr == nullptr) {
        return "kPD_NULLPTR";
    }

    // Calculate the total number of elements in the matrix
    int num_elements = mat.getWidth() * mat.getHeight();

    // Return the number of elements as an integer
    return num_elements;
}
