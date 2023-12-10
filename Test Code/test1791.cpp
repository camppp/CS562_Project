#include <iostream>
#include <vector>

// Define the fvm_lowered_cell_impl class for the multicore backend
template <typename Backend>
class fvm_lowered_cell_impl<Backend, Multicore> {
 public:
  // Constructor
  fvm_lowered_cell_impl(const ExecutionContext& ctx) : ctx_(ctx) {}

  // Implement the make_fvm_lowered_cell function
  static fvm_lowered_cell_impl* make_fvm_lowered_cell(BackendKind kind, const ExecutionContext& ctx) {
    if (kind == BackendKind::Multicore) {
      return new fvm_lowered_cell_impl<Backend, Multicore>(ctx);
    } else if (kind == BackendKind::GPU) {
      // Handle the case when the backend is specified as GPU
      // Assuming that the necessary GPU backend implementation is available
      return new fvm_lowered_cell_impl<Backend, GPU>(ctx);
    } else {
      // Handle the case when the backend is not supported
      std::cerr << "Unsupported backend kind: " << kind << std::endl;
      return nullptr;
    }
  }

  // Implement the member functions of the fvm_lowered_cell_impl class
  // ...

 private:
  // The execution context
  const ExecutionContext& ctx_;
};
