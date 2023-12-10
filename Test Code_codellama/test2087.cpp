template <typename T, typename Deleter>
class CustomUniquePtr {
public:
    CustomUniquePtr(T* ptr, Deleter deleter) : ptr_(ptr), deleter_(deleter) {}

    ~CustomUniquePtr() {
        deleter_(ptr_);
    }

    T* operator->() {
        return ptr_;
    }

    T& operator*() {
        return *ptr_;
    }

    CustomUniquePtr& operator=(T* ptr) {
        deleter_(ptr_);
        ptr_ = ptr;
        return *this;
    }

private:
    T* ptr_;
    Deleter deleter_;
};
