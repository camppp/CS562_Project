void moveZerosToEnd(int a[], int n) {
    int id = 0;  // Initialize a pointer to keep track of the position to place non-zero elements

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            // Swap non-zero element with the element at position id and increment id
            swap(a[id++], a[i]);
        }
    }
}
