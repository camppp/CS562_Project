// Function to calculate the time derivative of the spatial metric
void calculateTimeDerivative(const Scalar& lapse,
                             const Tensor& extrinsic_curvature,
                             Tensor& dt_spatial_metric,
                             const Vector& shift,
                             const Tensor& deriv_spatial_metric,
                             const Tensor& spatial_metric,
                             const Tensor& deriv_shift) {
  // Dimensionality of the spacetime
  const size_t SpatialDim = spatial_metric.dimension();

  // Loop over the indices to calculate the time derivative of the spatial metric
  for (size_t i = 0; i < SpatialDim; ++i) {
    for (size_t j = 0; j < SpatialDim; ++j) {
      // Calculate the time derivative using the given variables and operations
      dt_spatial_metric.get(i, j) = -2. * lapse * extrinsic_curvature.get(i, j);
      for (size_t k = 0; k < SpatialDim; ++k) {
        dt_spatial_metric.get(i, j) +=
            shift.get(k) * deriv_spatial_metric.get(k, i, j) +
            spatial_metric.get(k, i) * deriv_shift.get(j, k) +
            spatial_metric.get(k, j) * deriv_shift.get(i, k);
      }
    }
  }
}
