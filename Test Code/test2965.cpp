#include <span>
#include "scip/scip.h"

std::span<SCIP_Real> getVals(const SCIP_COL* col) {
    int num_nonz = SCIPcolGetNNonz(col);
    const SCIP_Real* vals = SCIPcolGetVals(col);
    return std::span<SCIP_Real>(vals, num_nonz);
}
