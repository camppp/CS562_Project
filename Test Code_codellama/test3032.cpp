template <typename T, size_t N>
class InplaceArray_Iterator {
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using iterator_category = std::random_access_iterator_tag;
    using difference_type = std::ptrdiff_t;

    InplaceArray_Iterator(T* ptr) : ptr_(ptr) {}

    reference operator*() const {
        return *ptr_;
    }

    pointer operator->() const {
        return ptr_;
    }

    // Other necessary iterator methods (not relevant to this problem) are already implemented
private:
    T* ptr_;
};
