class PtrMaybe {
public:
    PtrMaybe() : is_just(false), ptr(nullptr) {}
    PtrMaybe(T* ptr) : is_just(true), ptr(ptr) {}

    bool isJust() const { return is_just; }

    T* fromMaybe(T* defaultValue) const {
        if (is_just) {
            return ptr;
        } else {
            return defaultValue;
        }
    }

    T* fromJust() const {
        if (is_just) {
            return ptr;
        } else {
            throw std::runtime_error("PtrMaybe is Nothing");
        }
    }

    std::unique_ptr<T> takeJust() {
        if (is_just) {
            is_just = false;
            return std::unique_ptr<T>(ptr);
        } else {
            throw std::runtime_error("PtrMaybe is Nothing");
        }
    }

private:
    bool is_just;
    T* ptr;
};
