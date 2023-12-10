void remove(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    for (size_t i = index; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }

    size--;
}
