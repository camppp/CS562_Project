#include <iostream>
#include <vector>
#include <benchmark/benchmark.h>

// Matrix-vector multiplication function
std::vector<double> matrixVectorMultiplication(const std::vector<std::vector<double>>& matrix, const std::vector<double>& vector) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<double> result(rows, 0.0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i] += matrix[i][j] * vector[j];
        }
    }

    return result;
}

// Benchmark function
static void BM_MatrixVectorMultiplication(benchmark::State& state) {
    int size = state.range(0);
    std::vector<std::vector<double>> matrix(size, std::vector<double>(size, 1.0));
    std::vector<double> vector(size, 2.0);

    for (auto _ : state) {
        std::vector<double> result = matrixVectorMultiplication(matrix, vector);
        benchmark::DoNotOptimize(result);
    }
}

// Register the benchmark
BENCHMARK(BM_MatrixVectorMultiplication)->Arg(1 << 8)->Arg(1 << 10)->Arg(1 << 12);

// Run the benchmark
BENCHMARK_MAIN();
