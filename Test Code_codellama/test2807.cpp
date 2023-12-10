arm_compute::Status ClL2NormalizationWorkloadValidate(const TensorInfo& input) {
    // Check if the input tensor is a 4D tensor
    if (input.num_dimensions() != 4) {
        return arm_compute::Status::Error("Input tensor must be a 4D tensor");
    }

    // Check if the input tensor has a valid data type
    if (!input.is_valid_data_type()) {
        return arm_compute::Status::Error("Input tensor must have a valid data type");
    }

    // Check if the input tensor has a valid quantization information
    if (!input.is_valid_quantization_info()) {
        return arm_compute::Status::Error("Input tensor must have a valid quantization information");
    }

    // Check if the input tensor dimensions are valid for L2 normalization
    if (input.dimension(0) < 1 || input.dimension(1) < 1 || input.dimension(2) < 1 || input.dimension(3) < 1) {
        return arm_compute::Status::Error("Input tensor dimensions must be greater than 0");
    }

    // Check if the input tensor dimensions are valid for L2 normalization
    if (input.dimension(0) % 2 != 0 || input.dimension(1) % 2 != 0 || input.dimension(2) % 2 != 0 || input.dimension(3) % 2 != 0) {
        return arm_compute::Status::Error("Input tensor dimensions must be even numbers");
    }

    return arm_compute::Status::Success;
}
