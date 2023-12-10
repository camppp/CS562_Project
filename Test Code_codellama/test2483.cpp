bool comparePointers(int* rank8_ptr, int* rank8_target_ptr, int* rank1_ptr, int* rank1_target_ptr, int* rank2_ptr, int* rank2_target_ptr, int& offset_first, int& offset_last) {
    if (*rank8_ptr == *rank8_target_ptr && *rank1_ptr == *rank1_target_ptr && *rank2_ptr == *rank2_target_ptr) {
        offset_first = *rank8_ptr - *rank8_target_ptr;
        offset_last = *rank2_ptr - *rank2_target_ptr;
        return true;
    }
    return false;
}
