void bind(int index, const std::string& value) {
    // Check if the index is valid
    if (index < 0 || index >= query.size()) {
        throw std::invalid_argument("Invalid index");
    }

    // Bind the value to the index
    query[index] = value;
}
