#include <tiramisu/tiramisu.h>

int main(int argc, char **argv)
{
    // Define the dimensions of the matrices
    int M = 100;
    int K = 200;
    int N = 300;

    // Define the matrices A and B
    float *A = (float *) malloc(M * K * sizeof(float));
    float *B = (float *) malloc(K * N * sizeof(float));

    // Define the resulting matrix C
    float *C = (float *) malloc(M * N * sizeof(float));

    // Define the computation for matrix multiplication
    tiramisu::computation C_computation("C_computation", {A, B}, {C});

    // Define the computation for the matrix multiplication
    C_computation.set_arguments({A, B, C});
    C_computation.set_function_name("matrix_multiplication");

    // Define the computation for the matrix multiplication
    C_computation.set_dimensions({M, K, N});

    // Define the computation for the matrix multiplication
    C_computation.set_iterators({"i", "j", "k"});

    // Define the computation for the matrix multiplication
    C_computation.set_accesses({"A[i][k]", "B[k][j]", "C[i][j]"});

    // Define the computation for the matrix multiplication
    C_computation.set_reduction_dimension("k");

    // Define the computation for the matrix multiplication
    C_computation.set_reduction_function("+");

    // Define the computation for the matrix multiplication
    C_computation.set_reduction_output("C[i][j]");

    // Define the computation for the matrix multiplication
    C_computation.set_reduction_input("A[i][k] * B[k][j]");

    // Generate the C code for the computation
    C_computation.generate_code();

    // Free the memory allocated for the matrices
    free(A);
    free(B);
    free(C);

    return 0;
}
