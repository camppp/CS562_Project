class IOReleaser {
public:
    IOReleaser(io_object_t obj) : toRelease(obj) {}
    ~IOReleaser() {
        if (toRelease != 0)
            IOObjectRelease(toRelease);
    }
    IOReleaser(IOReleaser&& moved) : toRelease(moved.toRelease) {
        moved.toRelease = 0;
    }
    IOReleaser(IOReleaser const&) = delete;

    // Move assignment operator
    IOReleaser& operator=(IOReleaser&& moved) {
        if (this != &moved) {
            if (toRelease != 0) {
                IOObjectRelease(toRelease);
            }
            toRelease = moved.toRelease;
            moved.toRelease = 0;
        }
        return *this;
    }

    // Move constructor
    IOReleaser(IOReleaser&& moved) : toRelease(moved.toRelease) {
        moved.toRelease = 0;
    }

    // Getter for the io_object_t
    io_object_t get() const {
        return toRelease;
    }

private:
    io_object_t toRelease;
};
