int C(int n, int k) {
    // Initialize the union-find data structure with n+1 elements
    vector<int> parent(n+1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    // Use the union operation to merge sets based on the value of k
    for (int i = 0; i < k; i++) {
        int x = rand() % (n+1);
        int y = rand() % (n+1);
        if (x != y) {
            union(parent, x, y);
        }
    }

    // Calculate the number of combinations using the union-find data structure
    int num_combinations = 0;
    for (int i = 0; i <= n; i++) {
        if (parent[i] == i) {
            num_combinations++;
        }
    }

    return num_combinations;
}
