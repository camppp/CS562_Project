double Vj = V[j];
#pragma omp parallel for reduction(+:result[:n])
for (int i = 0; i < n; ++i) {
    result[i] += A[i][j] * Vj;
}
