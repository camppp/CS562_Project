class Tensor {
public:
    // Constructor for creating tensors based on the number of dimensions
    Tensor(int num_dims, const std::string& buffer_name, int num_batches, int num_channels, int width = 0) {
        if (num_dims == 3) {
            buffer_name = new pico_cnn::naive::Tensor(num_batches, num_channels, width);
        } else if (num_dims == 2) {
            buffer_name = new pico_cnn::naive::Tensor(num_batches, num_channels);
        } else if (num_dims == 1) {
            buffer_name = new pico_cnn::naive::Tensor(num_batches);
        }
    }
};
