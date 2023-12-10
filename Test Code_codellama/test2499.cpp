std::shared_ptr<Cut> NewCut(const int dim) {
  // Create a new cut object
  std::shared_ptr<Cut> cut = std::make_shared<Cut>();

  // Initialize the cut with appropriate points and weights based on the dimension
  if (dim == 1) {
    // For one-dimensional integration, use the trapezoidal rule
    cut->points = {0, 1};
    cut->weights = {0.5, 0.5};
  } else if (dim == 2) {
    // For two-dimensional integration, use the Simpson's rule
    cut->points = {0, 0.5, 1};
    cut->weights = {1.0/6, 2.0/3, 1.0/6};
  } else {
    // For higher dimensions, use the Gaussian quadrature
    cut->points = {0, 0.5, 1};
    cut->weights = {1.0/6, 2.0/3, 1.0/6};
  }

  return cut;
}
