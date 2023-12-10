size_t calculateMemoryAllocation(size_t dest_size, size_t text_size, size_t indents_size, size_t padding_size, size_t inner_indents_size) {
    return dest_size + text_size + indents_size + padding_size + inner_indents_size;
}
