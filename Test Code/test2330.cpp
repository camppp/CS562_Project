#include <memory>

namespace fea {

template <typename T, typename Deleter = std::default_delete<T>>
class SmartPointer {
public:
    // Implement the dereference operator to return an lvalue reference to the value pointed to by _ptr
    std::add_lvalue_reference_t<T> operator*() {
        return *_ptr;
    }

protected:
    const std::unique_ptr<T, Deleter> _ptr;
};

} // namespace fea
