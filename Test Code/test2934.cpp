template<typename T>
void BitBlock<T>::remove(size_t index) {
    // Check if the index is valid
    if (index >= size) {
        throw std::out_of_range("Index is out of range");
    }

    // Shift all subsequent elements to the left
    for (size_t i = index; i < size - 1; ++i) {
        elements[i] = elements[i + 1];
    }

    // Decrement the size
    --size;

    // Deallocate the last element
    delete elements[size];
    elements[size] = nullptr;
}
