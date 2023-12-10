long long maxNonAdjacentSum(int a[], int n) {
    if (n <= 0) return 0;
    if (n == 1) return max(0, a[0]);

    long long incl = a[0];
    long long excl = 0;
    long long excl_new;

    for (int i = 1; i < n; i++) {
        excl_new = max(incl, excl); // Update excl_new to the maximum of incl and excl
        incl = excl + a[i]; // Update incl to excl + current element
        excl = excl_new; // Update excl to excl_new
    }

    return max(incl, excl); // Return the maximum of incl and excl
}
