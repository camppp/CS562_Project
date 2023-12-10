int maxNonAdjacentSum(int a[], int n) {
    if (n <= 0) return 0;
    
    int incl = a[0];  // Maximum sum including the previous element
    int excl = 0;      // Maximum sum excluding the previous element
    
    for (int i = 1; i < n; i++) {
        // Current maximum excluding i
        int newExcl = (incl > excl) ? incl : excl;
        
        // Current maximum including i
        incl = excl + a[i];
        
        // Update excl for next iteration
        excl = newExcl;
    }
    
    // Return the maximum of incl and excl
    return (incl > excl) ? incl : excl;
}
