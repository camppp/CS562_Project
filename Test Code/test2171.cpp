void* allocate_memory(int len, int sz) {
    len -= 2;  // Reduce the available memory size by 2
    if (len >= sz) {
        void* allocated_memory = malloc(sz);  // Allocate memory of required size
        return allocated_memory;
    } else {
        return NULL;  // Return NULL if the available memory is insufficient
    }
}
