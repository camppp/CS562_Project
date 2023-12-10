class CustomVector {
public:
    // Default constructor
    CustomVector() : capacity_(0) {}

    // Method to check if the vector's capacity is 0
    bool isCapacityZero() {
        return capacity_ == 0;
    }

private:
    size_t capacity_;
};
