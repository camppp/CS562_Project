arm_compute::Status ClL2NormalizationWorkloadValidate(const TensorInfo& input,
{
    // Check if the input tensor is valid
    if (!input.is_resizable() || input.data_layout() != DataLayout::NHWC)
    {
        return arm_compute::Status(arm_compute::ErrorCode::RUNTIME_ERROR, "Invalid input tensor");
    }

    // Check if the input tensor data type is supported for L2 normalization
    if (input.data_type() != DataType::F16 && input.data_type() != DataType::F32)
    {
        return arm_compute::Status(arm_compute::ErrorCode::RUNTIME_ERROR, "Unsupported data type for L2 normalization");
    }

    // Check if the input tensor dimensions are compatible with L2 normalization
    const TensorShape& input_shape = input.tensor_shape();
    if (input_shape.num_dimensions() != 4 || input_shape[2] != 1 || input_shape[3] != 1)
    {
        return arm_compute::Status(arm_compute::ErrorCode::RUNTIME_ERROR, "Invalid input tensor dimensions for L2 normalization");
    }

    // Validation passed, return success status
    return arm_compute::Status::Success;
}
