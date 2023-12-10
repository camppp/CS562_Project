#include <tiramisu/core.h>
#include <tiramisu/debug.h>
#include <tiramisu/tiramisu.h>

int main(int argc, char* argv[]) {
    const int M = 10;
    const int K = 5;
    const int N = 8;

    // Declare Tiramisu function
    tiramisu::init("matrix_multiplication");

    // Declare input and output buffers
    tiramisu::buffer A("A", {tiramisu::expr(M), tiramisu::expr(K)}, tiramisu::p_uint8);
    tiramisu::buffer B("B", {tiramisu::expr(K), tiramisu::expr(N)}, tiramisu::p_uint8);
    tiramisu::buffer C("C", {tiramisu::expr(M), tiramisu::expr(N)}, tiramisu::p_uint8);

    // Define the computation
    tiramisu::var i("i", 0, M);
    tiramisu::var j("j", 0, N);
    tiramisu::var k("k", 0, K);
    tiramisu::computation C_init("C_init", {i, j}, tiramisu::expr((uint8_t)0));
    tiramisu::computation C_update("C_update", {i, j, k}, C(i, j) + A(i, k) * B(k, j));

    // Map the computations to a buffer
    C_init.store_in(&C, {i, j});
    C_update.set_expression(tiramisu::expr(o_add, C(i, j), A(i, k) * B(k, j)));
    C_update.store_in(&C, {i, j});

    // Generate the C code
    tiramisu::codegen({&A, &B, &C}, "generated_matrix_multiplication");

    return 0;
}
