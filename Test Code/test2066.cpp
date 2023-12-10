// Define the SortVal function to extract a value for comparison
static inline int SortVal(const _E& x) {
    // Implement the logic to extract a value from the element x
    // Example: Assuming _E has a member variable 'value', return x.value
    return x.value;
}

// Define the lt function to compare two elements based on SortVal
static inline bool lt(const _E& x, const _E& y) {
    return SortVal(x) < SortVal(y);
}

// Define the compare function to compare two arrays of elements
static inline int compare(const _E* p1, const _E* p2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (lt(p1[i], p2[i])) {
            return -1;  // p1 is less than p2
        } else if (lt(p2[i], p1[i])) {
            return 1;   // p1 is greater than p2
        }
    }
    return 0;  // p1 is equal to p2
}
