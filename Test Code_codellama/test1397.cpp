void calculate_dt_spatial_metric(const double& lapse, const Tensor& extrinsic_curvature, Tensor& dt_spatial_metric, const Vector& shift, const Tensor& deriv_spatial_metric, const Tensor& spatial_metric, const Tensor& deriv_shift) {
    // Calculate the time derivative of the spatial metric using the given variables and operations
    dt_spatial_metric = deriv_spatial_metric + lapse * extrinsic_curvature * spatial_metric + shift * deriv_shift;
}
