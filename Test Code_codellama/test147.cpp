#pragma omp parallel for private(i) shared(j)
for (int i = 0; i < 10; i++) {
    #pragma omp parallel for private(j) shared(i)
    for (int j = 0; j < 10; j++) {
        // some computation
    }
}
