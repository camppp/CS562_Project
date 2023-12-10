#include "backends/multicore/fvm.hpp"
#include "backends/gpu/fvm.hpp"
#include "fvm_lowered_cell_impl.hpp"

namespace arb {

// Define the fvm_lowered_cell_impl class for the multicore backend
template <typename Backend>
class fvm_lowered_cell_impl {
public:
    fvm_lowered_cell_impl(const execution_context& ctx) {
        // Implementation for the multicore backend
        // ...
    }
    // Other member functions and data members as needed
};

// Implement the make_fvm_lowered_cell function
fvm_lowered_cell_ptr make_fvm_lowered_cell(backend_kind p, const execution_context& ctx) {
    switch (p) {
    case backend_kind::multicore:
        return fvm_lowered_cell_ptr(new fvm_lowered_cell_impl<multicore::backend>(ctx));
    case backend_kind::gpu:
#ifdef ARB_HAVE_GPU
        return fvm_lowered_cell_ptr(new fvm_lowered_cell_impl<gpu::backend>(ctx));
#else
        throw std::runtime_error("GPU backend not available");
#endif
    default:
        throw std::runtime_error("Unsupported backend");
    }
}

} // namespace arb
