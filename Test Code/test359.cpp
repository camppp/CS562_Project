#include <iostream>
#include <variant>

struct default_init_tag {};

class VariantSupport {
public:
    VariantSupport(const default_init_tag&) {}

    template <typename T>
    void setValue(const T& value) {
        data_ = value;
    }

    template <typename T>
    T getValue() const {
        return std::get<T>(data_);
    }

private:
    std::variant<int, std::string, bool> data_;
};

int main() {
    VariantSupport variant(default_init_tag{});

    variant.setValue(42);
    std::cout << "Integer value: " << variant.getValue<int>() << std::endl;

    variant.setValue(std::string("Hello, Variant!"));
    std::cout << "String value: " << variant.getValue<std::string>() << std::endl;

    variant.setValue(true);
    std::cout << "Boolean value: " << std::boolalpha << variant.getValue<bool>() << std::endl;

    return 0;
}
