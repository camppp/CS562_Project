template <typename T>
class delegate_ref {
public:
    delegate_ref(T& func) : func_(func) {}

    T& operator()(int arg) {
        return func_(arg);
    }

    void verify() {
        // Verify the correctness of the invoked function or method
        // by checking the return value and/or the state of the
        // function or method.
    }

private:
    T& func_;
};
