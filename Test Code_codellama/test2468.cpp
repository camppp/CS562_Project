#pragma omp parallel for default(none) shared(A, V, result) private(i, j)
for (i = 0; i < A.size(); i++) {
    #pragma omp critical
    {
        for (j = 0; j < A[i].size(); j++) {
            result[i] += A[i][j] * V[j];
        }
    }
}
