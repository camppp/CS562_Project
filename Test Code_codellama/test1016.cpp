void computeInner_stencil2d(int i, int j, int k, int l, int m, int n) {
    int A[m][n];
    int B[m][n];
    int C[m][n];

    // Initialize A, B, and C matrices
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
            B[i][j] = 0;
            C[i][j] = 0;
        }
    }

    // Perform the stencil operation
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = A[i][j] + B[i][j];
            C[i][j] = C[i][j] + A[i][j];
        }
    }

    // Print the result
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}
