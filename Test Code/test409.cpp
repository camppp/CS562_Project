class Tensor {
public:
    // Constructor for creating tensors based on the number of dimensions
    Tensor(int num_dims, const std::string& buffer_name, int num_batches, int num_channels, int width = 0) {
        // Initialize the tensor based on the number of dimensions
        if (num_dims == 3) {
            // Create a 3-dimensional tensor with dimensions num_batches x num_channels x width
            tensor_ = std::make_shared<Tensor3D>(num_batches, num_channels, width);
        } else if (num_dims == 2) {
            // Create a 2-dimensional tensor with dimensions num_batches x num_channels
            tensor_ = std::make_shared<Tensor2D>(num_batches, num_channels);
        } else if (num_dims == 1) {
            // Create a 1-dimensional tensor with dimensions num_batches
            tensor_ = std::make_shared<Tensor1D>(num_batches);
        } else {
            // Throw an exception if the number of dimensions is not valid
            throw std::invalid_argument("Invalid number of dimensions");
        }

        // Set the buffer name
        buffer_name_ = buffer_name;
    }

private:
    // The tensor buffer
    std::shared_ptr<TensorBuffer> tensor_;

    // The buffer name
    std::string buffer_name_;
};
