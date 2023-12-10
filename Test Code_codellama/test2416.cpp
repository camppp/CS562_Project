class Reference {
public:
    Reference(T* obj) : obj_(obj), ref_count_(1) {}

    void grabReference(T* obj) {
        if (obj_ == obj) {
            ref_count_++;
        } else {
            throw std::runtime_error("Invalid reference");
        }
    }

    void releaseReference(T* obj) {
        if (obj_ == obj) {
            ref_count_--;
            if (ref_count_ == 0) {
                delete obj_;
                obj_ = nullptr;
            }
        } else {
            throw std::runtime_error("Invalid reference");
        }
    }

private:
    T* obj_;
    int ref_count_;
};
