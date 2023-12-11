class IOReleaser {
public:
    IOReleaser(io_object_t toRelease) : toRelease(toRelease) {}
    ~IOReleaser() {
        if (toRelease != nullptr) {
            IOObjectRelease(toRelease);
        }
    }
    IOReleaser(IOReleaser&& other) noexcept : toRelease(other.toRelease) {
        other.toRelease = nullptr;
    }
    IOReleaser& operator=(IOReleaser&& other) noexcept {
        if (this != &other) {
            toRelease = other.toRelease;
            other.toRelease = nullptr;
        }
        return *this;
    }
private:
    io_object_t toRelease;
};
