#include <cstddef>
#include <span>
#include <scip/scip.h>

std::span<SCIP_Real> getVals(const SCIP_COL* col) {
    // Get the number of non-zero elements in the column
    int nnz = SCIPcolGetNNonz(col);

    // Allocate memory for the values
    SCIP_Real* vals = new SCIP_Real[nnz];

    // Get the values from the column
    SCIP_Real* vals_ptr = SCIPcolGetVals(col);
    for (int i = 0; i < nnz; ++i) {
        vals[i] = vals_ptr[i];
    }

    // Return the values as a non-modifiable span
    return std::span<SCIP_Real>(vals, nnz);
}
