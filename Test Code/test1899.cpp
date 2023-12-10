#include <memory>
#include <vector>

class Shape {
public:
    Shape(int batch, int height, int width, int channels) : batch_(batch), height_(height), width_(width), channels_(channels) {}

    int batch() const { return batch_; }
    int height() const { return height_; }
    int width() const { return width_; }
    int channels() const { return channels_; }

private:
    int batch_;
    int height_;
    int width_;
    int channels_;
};

class Tensor {
public:
    Tensor(std::shared_ptr<Shape> shape) : shape_(shape) {}

    std::shared_ptr<Shape> shape() const { return shape_; }

    std::shared_ptr<Tensor> Broaden() {
        // Implementation of Broaden function
        return std::make_shared<Tensor>(shape_);
    }

    void set_shape(std::shared_ptr<Shape> shape) {
        shape_ = shape;
    }

private:
    std::shared_ptr<Shape> shape_;
};

std::shared_ptr<Tensor> DepthToSpaceInfer(std::shared_ptr<Tensor> input_x, int block_size) {
    auto input_shape = input_x->shape();
    int batch = input_shape->batch();
    int height = input_shape->height();
    int width = input_shape->width();
    int channels = input_shape->channels();

    int new_height = height * block_size;
    int new_width = width * block_size;
    int new_channels = channels / (block_size * block_size);

    auto ret = input_x->Broaden();
    ret->set_shape(std::make_shared<Shape>(batch, new_height, new_width, new_channels));
    return ret;
}
