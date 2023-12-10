#include <iostream>
#include <functional>
#include <cassert>

template <typename T>
class delegate_ref {
    std::function<T> func;

public:
    delegate_ref(std::function<T> f) : func(f) {}

    T operator()(int arg) {
        return func(arg);
    }

    void operator=(std::function<T> f) {
        func = f;
    }
};

int f1(int x) {
    return x * 2;
}

int f2(int x) {
    return x * 2;
}

int main() {
    int i1, i2;
    delegate_ref<int(int)> d(f1);
    i1 = d(2);
    assert(i1 == 4);

    d = f2;
    i2 = d(4);
    assert(i2 == 8);

    std::cout << "All checks passed successfully!" << std::endl;

    return 0;
}
