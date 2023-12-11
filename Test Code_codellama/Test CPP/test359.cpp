#include <iostream>
#include <string>
#include <typeinfo>

class VariantSupport {
public:
    VariantSupport(default_init_tag) {}

    template <typename T>
    void set_value(T value) {
        if (typeid(T) == typeid(int)) {
            int_value = value;
        } else if (typeid(T) == typeid(std::string)) {
            string_value = value;
        } else if (typeid(T) == typeid(bool)) {
            bool_value = value;
        } else {
            throw std::runtime_error("Unsupported type");
        }
    }

    template <typename T>
    T get_value() {
        if (typeid(T) == typeid(int)) {
            return int_value;
        } else if (typeid(T) == typeid(std::string)) {
            return string_value;
        } else if (typeid(T) == typeid(bool)) {
            return bool_value;
        } else {
            throw std::runtime_error("Unsupported type");
        }
    }

private:
    int int_value;
    std::string string_value;
    bool bool_value;
};

int main() {
    VariantSupport variant(default_init_tag());

    variant.set_value<int>(10);
    std::cout << "int value: " << variant.get_value<int>() << std::endl;

    variant.set_value<std::string>("hello");
    std::cout << "string value: " << variant.get_value<std::string>() << std::endl;

    variant.set_value<bool>(true);
    std::cout << "bool value: " << variant.get_value<bool>() << std::endl;

    return 0;
}
